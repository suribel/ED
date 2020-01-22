#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

struct info{
	int a, b;
    char c;
    int sol;
	
	info(int aa = 0, int bb = 0, int solucion = 0, char cc = 'n'){
		a = aa;
        b = bb;
        c = cc;
        sol = solucion;
	}
};


    
bool cifras(vector<int> sol, int res, int & parcial,  vector<info> & datos_finales, vector<info> datos, int nivel=0){

    bool encontrado = false;

    //vector de copia del original
    vector<int> sol2;

    for (int i = 0; i < sol.size() && !encontrado; i++)
    {
        for (int j = i+1; j < sol.size() && !encontrado; j++)
        {
            //bucle de operaciones 1 = +, 2 = *, 3 = -, 4 = /
            for (int z = 0; z < 3 && !encontrado; z++) 
            {
                sol2 = sol;
                int resultado = 0;
                int cont;                    

                    //////////////////////////////////////// SUMA  ////////////////////////////////////////
                if (z == 0)
                {
                    resultado = sol[i]+sol[j];

                    info operaciones(sol[i], sol[j], resultado, '+');                        
                    
                    //meto las operaciones en el vector parcial de datos
                    datos[nivel]=operaciones;
                    
                    //Si resultado es la solucion
                    if (resultado == res)
                    {
                        encontrado = true;
                        parcial = resultado;
                        //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                        datos_finales.clear();
                        datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);
                    }
                    else{
                        //Compruebo si el resultado es el mas proximo al nuero que queremos encontrar
                        cont = abs(res - resultado);
                        if (abs(res - parcial) > cont)
                        {
                            //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                            datos_finales.clear();
                            datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);

                            parcial = resultado;                                
                        }
                        
                        sol2.erase(sol2.begin()+j);
                        sol2.erase(sol2.begin()+i);
                        sol2.insert(sol2.begin(),resultado);
                        encontrado = cifras(sol2, res, parcial, datos_finales, datos, nivel+1);
                        
                    }
                }
                //////////////////////////////////////// PRODUCTO  ////////////////////////////////////////
                if (z == 1)
                {
                    resultado = sol[i]*sol[j];

                    info operaciones(sol[i], sol[j], resultado, 'x');                        
                    
                    //meto las operaciones en el vector parcial de datos
                    datos[nivel]=operaciones;
                    
                    if (resultado == res)
                    {
                        encontrado = true;
                        parcial = resultado;
                        //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                        datos_finales.clear();
                        datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);
                    }
                    else
                    {
                        //Compruebo si el resultado es el mas proximo al nuero que queremos encontrar
                        cont = abs(res - resultado);
                        if (abs(res - parcial) > cont)
                        {
                            //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                            datos_finales.clear();
                            datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);

                            parcial = resultado;                                
                        }
                        
                        sol2.erase(sol2.begin()+j);
                        sol2.erase(sol2.begin()+i);
                        sol2.insert(sol2.begin(),resultado);
                        encontrado = cifras(sol2, res, parcial, datos_finales, datos, nivel+1);
                        
                    }                 
                }
                //////////////////////////////////////// RESTA ////////////////////////////////////////
                if (z == 2)
                {

                    if (sol[i]>sol[j])
                    {
                        resultado = sol[i]-sol[j];
                        info operaciones(sol[i], sol[j], resultado, '-');    
                        //meto las operaciones en el vector parcial de datos
                        datos[nivel]=operaciones; 
                    }
                    else
                    {
                        resultado = sol[j]-sol[i];                            
                        info operaciones(sol[j], sol[i], resultado, '-');   
                        //meto las operaciones en el vector parcial de datos
                        datos[nivel]=operaciones; 
                    }                                
                    
                    if (resultado == res)
                    {
                        encontrado = true;
                        parcial = resultado;
                        //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                        datos_finales.clear();
                        datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);
                    }
                    else
                    {   
                        //Compruebo si el resultado es el mas proximo al nuero que queremos encontrar
                        cont = abs(res - resultado);
                        if (abs(res - parcial) > cont)
                        {
                            //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                            datos_finales.clear();
                            datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);

                            parcial = resultado;                                
                        }
                        
                        sol2.erase(sol2.begin()+j);
                        sol2.erase(sol2.begin()+i);
                        sol2.insert(sol2.begin(),resultado);
                        encontrado = cifras(sol2, res, parcial, datos_finales, datos, nivel+1);
                        
                    }                 
                }
                //////////////////////////////////////// DIVISION  ////////////////////////////////////////
                if (z == 3)
                {
                    bool correcto = false;                        

                    if (sol[i]>sol[j])
                    {
                        if ((sol[i]%sol[j]) == 0)
                        {
                            correcto = true;
                            resultado = sol[i]/sol[j];
                            info operaciones(sol[i], sol[j], resultado, '/');    
                            //meto las operaciones en el vector parcial de datos
                            datos[nivel]=operaciones;
                            correcto = true;       
                        }
                    }
                    else
                    {
                        if ((sol[j]%sol[i]) == 0)
                        {
                            correcto = true;
                            resultado = sol[j]/sol[i];
                            info operaciones(sol[j], sol[i], resultado, '/');    
                            //meto las operaciones en el vector parcial de datos
                            datos[nivel]=operaciones; 
                            correcto = true;       
                        }
                    }                                
                    
                    if (correcto)
                    {
                        if (resultado == res)
                        {
                            encontrado = true;
                            parcial = resultado;
                            //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                            datos_finales.clear();
                            datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);
                        }
                        else
                        {
                            //Compruebo si el resultado es el mas proximo al nuero que queremos encontrar
                            cont = abs(res - resultado);
                            if (abs(res - parcial) > cont)
                            {
                                //guardo en el vector final lo que llevo acumulado en el vector de datos hasta el nivel en el que me encuentro
                                datos_finales.clear();
                                datos_finales.insert(datos_finales.begin(),datos.begin(),datos.begin()+nivel+1);

                                parcial = resultado;                                
                            }
                            
                            sol2.erase(sol2.begin()+j);
                            sol2.erase(sol2.begin()+i);
                            sol2.insert(sol2.begin(),resultado);
                            encontrado = cifras(sol2, res, parcial, datos_finales, datos, nivel+1);
                            
                        }      
                    }                          
                }

            }
        }        
    }    
    
    return encontrado;    
}

int main(){

    srand(time(NULL));

    vector<int> v;
    vector<int> c;
    vector<info> datos;
    vector<info> datos2;
    vector<info> datosf;

    info gg;

    for (int i = 0; i < 6; i++)
    {
        datos2.push_back(gg);
    }
    

    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(4);
    c.push_back(5);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);
    c.push_back(9);
    c.push_back(10);
    c.push_back(25);
    c.push_back(50);
    c.push_back(75);
    c.push_back(100);
    
    for (int i = 0; i < 6; ++i)
    {
        int num = rand() % c.size();
        v.push_back(c[num]);
    }

    cout << "---------------------" << endl;

    for (int i = 0; i < 6; ++i)
    {
        cout << v[i] << " ";
    }
    
    int parcial = 0;
    int resultado = 100 + rand() % 899;


    cout << endl << resultado <<endl;
    cout << "---------------------" << endl;

    if (cifras(v,resultado, parcial, datos, datos2))
    {
        cout << "Solucion exacta" << endl;
    }
    else
    {
        cout << "Solucion parcial" << endl;
    }

    //limpiamos el vector de posibles operaciones inecesarias
    if (datos.size()>1)
    {
        datosf.push_back(datos.back());
        for (int i = datos.size()-1; i > 0; i--)
        {
            for (int j = datos.size()-2; j > 0; j--)
            {
                if (datos[i].a == datos[j].sol || datos[i].b == datos[j].sol)
                {
                    datosf.insert(datosf.begin(),datos[j]);
                }
            }
            
        }

        //Sacamos las operaciones
        for (int i = 0; i < datosf.size(); ++i)
        {
            cout << datosf[i].a <<  " " << datosf[i].c <<  " " << datosf[i].b <<  " = " << datosf[i].sol << endl;
        }        
        
    }
    else
    {
        //Sacamos las operaciones
        for (int i = 0; i < datos.size(); ++i)
        {
            cout << datos[i].a <<  " " << datos[i].c <<  " " << datos[i].b <<  " = " << datos[i].sol << endl;
        }

    }    
    
    cout << "---------------------" << endl;


}