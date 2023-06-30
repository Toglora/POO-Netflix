
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class video{
    public:
        video();
        video(int id, string name, int dur);
        virtual void MostrarCalificacion();
        void setCalificacion(int cal);
        int getCalificacion();
        string getNombre();
        void Reproduce();
        friend ostream & operator << (ostream &out, const video &t);
        virtual void MuestraVideo() = 0;
        virtual string getGenero() = 0;
    protected:
        int ID;
        string Nombre;
        int Duracion;
        int Calificacion;
};
video::video(){
    ID = 0;
    Nombre = " ";
    Duracion = 0;
    Calificacion = 0;
}
video::video(int id, string name,int dur){
    ID = id;
    Nombre = name;
    Duracion = dur;
}

void video::setCalificacion(int cal){
    if(100 >= cal >= 0){
        Calificacion = cal;
    }else{
        Calificacion = 0;
    }
    
}

int video::getCalificacion(){
    return Calificacion;
}

void video :: MostrarCalificacion(){
    cout << "La calificacion del video: " << Nombre << "es: "<< Calificacion;
}

void video :: Reproduce(){
    cout << "*SE REPRODUCE " << Nombre <<"*";
}

ostream & operator << (ostream &out, const video &t) 
{ 
    out << t.ID <<" "<< t.Nombre <<" "<<t.Duracion<<endl;
    out << "Calificacion: " << t.Calificacion;
    return out; 
}

string video::getNombre(){
    return Nombre;
}
void video :: MuestraVideo(){
   cout << ID <<" "<< Nombre <<" "<<Duracion<<endl;
}

class pelicula:public video{
    public:
        pelicula();
        pelicula(int idd, string namee,int durr, string gen);
        void MostrarCalificacion();
        friend ostream & operator << (ostream &out, const pelicula &p);
        void MuestraVideo();
        string getGenero();
    private:
        string Genero;
    
};
pelicula::pelicula(){
    Genero = " ";
}
pelicula::pelicula(int idd, string namee,int durr, string gen): video(idd, namee, durr){
    Genero = gen;
}
void pelicula::MostrarCalificacion(){
     cout << "La calificacion de la pelicula: " << Nombre << "es: "<< Calificacion;
}
ostream & operator << (ostream &out, const pelicula &p) 
{ 
    out << p.ID <<" "<< p.Nombre <<" "<<p.Duracion<< " " << p.Genero;
    //out << "Calificacion: " << p.Calificacion;
    return out; 
}

void pelicula :: MuestraVideo(){
    cout << ID <<" "<< Nombre <<" "<<Duracion<< " " << Genero;

}

string pelicula::getGenero(){
    return Genero;
}

class serie:public video{
    public:
        serie();
        serie(int idd, string namee,int durr, string gen, string tit, int temp);
        void MostrarCalificacion();
        friend ostream & operator << (ostream &out, const serie &s);
        void MuestraVideo();
        string getGenero();
    private:
        string Genero;
        string Titulo;
        int Temporada;
};

serie::serie(){
    Genero = " ";
    Titulo = " ";
    Temporada = 0;
}
serie :: serie(int idd, string namee,int durr, string gen, string tit, int temp): video(idd, namee, durr){
    Genero = gen;
    Titulo = tit;
    Temporada = temp;
}
void serie::MostrarCalificacion(){
    cout << "La calificacion de la serie: " << Nombre << "es: "<< Calificacion;
}

ostream & operator << (ostream &out, const serie &s) 
{ 
    out << s.ID <<" "<< s.Nombre <<" "<<s.Duracion<< " " << s.Genero << " " << s.Titulo << " " << s.Temporada;
    //out << "Calificacion: " << s.Calificacion;
    return out; 
}

void serie :: MuestraVideo(){
    cout << ID <<" "<< Nombre <<" "<<Duracion<< " " << Genero << " " << Titulo << " " << Temporada;

}

string serie::getGenero(){
    return Genero;
}

int main()
{
    ifstream archivoVideos;
    string linea, x, z, a, w, v, archivoCarga, respGenero, names, lengh;
    int id, y, b, u;
    int i=0,e = 0, j = 0, respMenu, respCali, califi, tamSeries = 0, tamMovies = 0, tamTotal = 0;
    serie listSerie[100];
    pelicula listMovie[100];
    video *listVideo[100];
    
    menu:
    cout <<"***********************************************" << endl;
    cout << "Bienvenido" << endl << endl;
    cout << "1. Cargar archivo de datos" << endl <<
    "2. Mostrar los videos en general con una cierta "<< 
    "calificación o de un cierto género" << endl << 
    "3. Mostrar los episodios de una determinada "<< 
    "serie con una calificacion determinada"<<
    endl << "4. Mostrar las películas con cierta "<< 
    "calificacion" << endl << "5. Calificar un video"<< 
    endl << "0. Salir" << endl <<
    "************************************************" << endl;
    cin >> lengh;
    while(lengh != "1" && lengh != "2" && lengh != "3" && lengh != "4" && lengh != "5" && lengh != "0"){
        cout << "Ingrese una opcion valida... " << endl;
        return main();
    }
    respMenu = stoi(lengh);
    while(respMenu != 1 && respMenu != 2 && respMenu != 3 && respMenu != 4 && respMenu != 5 && respMenu != 0){
        cout << "Ingrese una opcion valida: " << endl;
        return main();
    }
    switch(respMenu){
        case 1:
            cout << "Escriba el archivo que desea cargar: " << endl;
            cin >> archivoCarga;
            archivoVideos.open(archivoCarga);
            if(archivoVideos.fail()){
                cout << "No existe el archivo" << endl << endl;
                goto menu;
            }else{
                cout << "Si existe el archivo" << endl;
                while (getline(archivoVideos, linea))
                {
                    while (archivoVideos >> id) 
                    { 
                        if (id%2==0) 
                        {
                            archivoVideos >> x >> y >> z >> a >> b; 
                            serie series(id,x,y,z,a,b);
                            listSerie[e] = series;
                            listVideo[j] = &listSerie[e];
                            e++;
                            tamSeries++;
                        }else{ 
                            archivoVideos >> w >> u >> v;
                            pelicula movie(id, w, u, v);
                            listMovie[i] = movie;
                            listVideo[j] = &listMovie[i];
                            i++;
                            tamMovies++;
                        } 
                        j++;
                        tamTotal++;
                    }
                }
                archivoVideos.close();
                goto menu;
            }
        case 2:
            menu2:
            cout << "******************************************" << endl;
            cout << "Mostrar videos por: " << endl;
            cout << "1. Calificacion" << endl << "2. Genero"<<
            endl << "0. Resgresar al menu principal" << endl;
            cout << "******************************************" << endl;
            cin >> lengh;
            while(lengh != "1" && lengh != "2" && lengh != "3" && lengh != "4" && lengh != "5" && lengh != "0"){
                cout << "Ingrese una opcion valida... " << endl;
                goto menu2;
            }
            respMenu = stoi(lengh);
            switch(respMenu){
                case 0:
                    goto menu;
                case 1: 
                    cout << "Ingresa la calificación de interes: " << endl;
                    cin >> respCali;
                    cout <<"Series y peliculas con calificación de " << respCali <<": "<<endl << endl;
                    for(i=0;i<tamTotal;i++){
                        if(listVideo[i]->getCalificacion()==respCali){
                            listVideo[i]->MuestraVideo();
                            cout << endl;
                        }
                    }
                    cout << endl;
                    goto menu2;
                    break;
                case 2:
                    cout << "Ingresa el genero de interes: "<< endl;
                    cin >> respGenero;
                    cout <<"Series y peliculas con genero de " << respGenero <<": "<<endl << endl;
                    for(i=0;i<tamTotal;i++){
                        if(listVideo[i]->getGenero()==respGenero){
                            listVideo[i]->MuestraVideo();
                            cout << endl;
                        }
                    }
                    cout << endl;
                    goto menu2;
                    break;
            }
        case 3:
            cout << "Ingresa la calificación de interes: " << endl;
            cin >> respCali;
            cout <<"Series con calificación de " << respCali <<": "<<endl;
            for(i=0;i<tamSeries;i++){
                if(listSerie[i].getCalificacion()==respCali){
                    cout<<listSerie[i];
                    cout << endl;
                }
            }
            cout << endl;
            goto menu;
            break;
        case 4:
            cout << "Ingresa la calificación de interes: " << endl;
            cin >> respCali;
            cout <<"Peliculas con calificación de " << respCali <<": "<<endl;
            for(i=0;i<tamMovies;i++){
                if(listMovie[i].getCalificacion()==respCali){
                    cout<<listMovie[i];
                    cout << endl;
                }
            }
            cout << endl;
            goto menu;
            break;
        case 5:
            cout << "Ingresa el nombre de la serie o pelicula a calificar: " << endl;
            cin >> names;
            for(i=0; i<tamTotal; i++){
                if(listVideo[i]->getNombre() == names){
                    cout<<"Ingresa la calificacion a dar de 0 a 10: "<<endl;
                    cin >> califi;
                    while(10 < califi || 0>califi){
                        cout << "Debe darle una valoracion de 0 a 10: " << endl;
                        cin >> califi;
                    }
                    listVideo[i]->setCalificacion(califi);
                    goto menu;
                }
            }
            cout <<"No se encontro ninguna coicidencia con la busqueda"<<endl;
            goto menu;
            break;
            
        case 0:
            exit(0);
            
        default:
            cout << "Ingrese una opcion valida"<< endl;
            return main();
    }
    
    return 0;
}