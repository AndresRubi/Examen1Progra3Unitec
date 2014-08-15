#include <iostream>

using namespace std;

class PersonajeTablero
{
public:
    PersonajeTablero *sig;
    int pos_x, pos_y, hp, ataque, jugador;
PersonajeTablero(int pos_x,int pos_y,int hp,int ataque,int jugador)
{
    this->pos_x=pos_x;
    this->pos_y=pos_y;
    this->hp=hp;
    this->ataque=ataque;
    this->jugador=jugador;
    sig=NULL;
}
};

class ListaPersonajes
{
public:
PersonajeTablero*inicio;
ListaPersonajes()
{
    inicio=NULL;
}
void agregar(PersonajeTablero* nuevop)
{
    if(inicio==NULL)
        {
            inicio=nuevop;
        }else
        {
            PersonajeTablero*temp=inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig=nuevop;
        }


}

void cargarDesdeArchivo(string)
{

}

void escribirEnArchivos(string)
{

}

void danoDeArea(int dano, int jugador)
{
    PersonajeTablero*temp = inicio;
        while(temp != NULL)
        {
            if(jugador == temp->jugador)
                temp->hp=temp->hp-dano;
            temp = temp->sig;
        }

}
void debilitadorDeArea(int debilitador, int jugador)
{
    PersonajeTablero*temp = inicio;
        while(temp != NULL)
        {
            if(jugador == temp->jugador)
                temp->ataque=temp->ataque-debilitador;
            temp = temp->sig;
        }
}

void curadorDeArea(int curacion, int jugador)
{
     PersonajeTablero*temp = inicio;
        while(temp != NULL)
        {
            if(jugador == temp->jugador)
                temp->hp=temp->hp+curacion;
            temp = temp->sig;
        }
}

void imprimir()
    {
        for(PersonajeTablero*temp=inicio;temp!=NULL;temp=temp->sig)
        {
        cout<<"vida"<<endl;
        cout<<temp->hp<<endl;
        cout<<"ataque"<<endl;
        cout<<temp->ataque<<endl;
        cout<<"tipojugador"<<endl;
        cout<<temp->jugador<<endl;
        cout<<""<<endl;


        }
    }
};

int main()
{
   ListaPersonajes *lp=new ListaPersonajes();
  lp->agregar(new PersonajeTablero(1,2,5,4,1));
  lp->agregar(new PersonajeTablero(1,2,5,4,1));
  lp->agregar(new PersonajeTablero(1,2,5,4,2));
  lp->agregar(new PersonajeTablero(1,2,5,4,3));
  lp->imprimir();
  lp->danoDeArea(2,1);
  lp->imprimir();
  lp->debilitadorDeArea(1,3);
  lp->imprimir();
  lp->curadorDeArea(10,2);
  lp->imprimir();
    cout << "Hello world!" << endl;
    return 0;
}
