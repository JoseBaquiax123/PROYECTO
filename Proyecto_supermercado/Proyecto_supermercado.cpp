
#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;

int main()
{
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "empres@123", "supermercado", 3306, NULL, 0);
    if (conectar) {
       //cout << "conexion exitosa..." << endl;
        string puesto;
        cout << "ingrese puesto: ";
        cin >> puesto;
        string insert = "insert into puestos(puesto) values('" + puesto + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar,i);
        if (!q_estado) {
            cout << "ingreso exitoso..." << endl;

        }
        else {
        cout << "error al ingresar" << endl;
    }
       string consulta = "select * from puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {

                cout << fila[0] << "," << fila[1] << endl;
            }

        }
        else {
            cout << "error al consultar" << endl;
        }
    }
    else {
        cout << "error" << endl;
    }
    system("pause");
    return 0;
}
