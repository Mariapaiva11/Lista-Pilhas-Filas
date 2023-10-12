Lista 1 – Pilhas e filas;



#include <iostream>
#include <locale>
#include <string>

using namespace std;

class NoDeque{
public:
    int info;
    NoDeque* inicio;
    NoDeque* fim;
};

class Deque{
public:
    NoDeque* frente;
    NoDeque* verso;
    int contador_frente,contador_verso;

    void cria (){
        this->frente = 0;
        this->verso = 0;
        contador_frente = 0;
        contador_verso = 0;
    }

    void insereInicio(int valor){
        auto* no1 = new NoDeque{.info = valor, .inicio = this->frente};
        no1 = this->frente;
        mostrar_insere_inicio(valor);
        contador_frente++;
    }

    void insereFim(int valor){
        auto* no2 = new NoDeque{.info = valor, .inicio = this->verso};
        no2 = this->verso;
        mostrar_insere_fim(valor);
        contador_verso++;
    }

    void removeInicio (){
        NoDeque* d = this->frente->inicio;
        mostrar_remove_inicio();
        delete this->frente;
        d = this->frente;
        contador_frente--;
    }

    void removeFim (){
        NoDeque* d= this->verso->fim;
        mostrar_remove_fim();
        delete this->verso;
        d = this->verso;
        contador_verso--;
    }

    void buscaInicio(){
        if(this -> contador_frente == 0){
            cout << "Nao possui info na frente" << "\n\n";
        }
        else {
            cout << "A info do inicio: " << this -> frente -> info << "|\n";
        }
    }

    void buscaFim(){
        if(this -> contador_verso==0){
            cout << "Nao tem nenhuma info na frente" <<"\n\n";
        }
        else {
            cout << "O info do fim é " << this -> verso -> info <<"|\n";
            }
        }

    void mostrar_insere_inicio(int info){
        cout <<"O valor inserido na frente foi: "<<info<<"\n\n";
    }

    void mostrar_insere_fim(int info){
        cout <<"O valor inserido no verso foi: "<<info<<"\n\n";
    }

    void mostrar_remove_inicio(){
        cout <<"O valor removido na frente foi: "<<this->frente->info<<"\n\n";
    }

    void mostrar_remove_fim(){
        cout <<"O valor removido na frente foi: "<<this->verso->info<<"\n\n";
    }
};

int main (){
    Deque d;
    d.insereInicio(10);
    d.insereFim(15);
    return 0;
}



#include <iostream>
#include <queue>

using namespace std;

queue<int> Fila1;
queue<int> Fila2;

void enfila(int valor) {
    Fila1.push(valor);
};

void topo() {
    if (Fila1.size() > 0) {
        cout << "\nO topo da pilha é: "<< Fila1.back() << endl;

    } else {
        cout << "\nNao existe itens na pilha!\n";
    }
};

void desempilha() {
    int n,i;
    n = Fila1.size();
    if (n==0) {
        cout << "\nNao existe itens na pilha!\n";
    }

    if (n==1){
        cout << "\nO valor desempilhado foi: " << Fila1.front();
        Fila1.pop();
    }
    if (n > 1) {
        for ( i = 0; i < n; i++) {
            if (i+1==n){
                cout << "\nO valor desempilhado foi: " << Fila1.front() ;
                Fila1.pop();
            }
            else{
                Fila2.push(Fila1.front());
                Fila1.pop();
            }
        }
        int n2=Fila2.size();
        for ( i = 0; i < n2; i++) {
            Fila1.push(Fila2.front());
            Fila2.pop();
        }
    }
};

int main (){
    int opcao = 0;

    while (opcao != 4){
        cout << "\n---------------------------------\nSelecione uma Posicao\n---------------------------------\n";
        cout <<"\n1 - Inserir numero na Fila\n---------------------------------\n";
        cout <<"\n2 - Remover numero na Fila\n---------------------------------\n";
        cout <<"\n3 - Inserir numero na Fila\n---------------------------------\n";
        cout <<"\n4 - Sair do Programa\n---------------------------------\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int numero;
                cout << "\nDigite o valor que deseja inserir na Pilha: ";
                cin >> numero;
                cout << "\nO numero inserido na Pilha foi: " << numero<<endl;
                enfila(numero);
                break;

            case 2:
                desempilha();
                break;

            case 3:
                topo();
                break;

            case 4:
                cout << "\nFim \n";
                break;

            default:
                cout << "\nOpcao invalida, digite uma opcao valida!\n";
                break;
        }
    }

}


#include <iostream>
#include <stack>

using namespace std;

stack<int> Pilha1;
stack<int> Pilha2;

void empilha (int valor){
    Pilha1.push(valor);
}

void topo (){
    if (Pilha1.size() > 0) {
        cout << "\nO topo da fila e: "<< Pilha1.top() << endl;

    } else {
        cout << "\nNao existe itens na fila!\n";
    }
}

void desenfila(){
    int i,n;
    n = Pilha1.size();
    if (n==0) {
        cout << "\nNao existe itens na fila!\n";
    }

    if (n==1){
        cout << "\nO valor desempilhado foi: " << Pilha1.top();
        Pilha1.pop();
    }
    if (n > 1) {
        for (i=0;i<n;i++){
            if(i+1==n){
                cout << "\nO numero removido da pilha e: " << Pilha1.top() <<endl;
                Pilha1.pop();
            }
            else{
                Pilha2.push(Pilha1.top());
                Pilha1.pop();
            }
        }

        int n2=Pilha2.size();

        for (i=0;i<n2;i++){
            Pilha1.push(Pilha2.top());
            Pilha2.pop();
        }
    }
}

int main (){
    int opcao=0;

    while (opcao != 3){
        cout << "\n---------------------------------\nSelecione uma Posicao\n---------------------------------\n";
        cout <<"\n1 - Inserir numero na Fila\n---------------------------------\n";
        cout <<"\n2 - Remover numero na Fila\n---------------------------------\n";
        cout <<"\n3 - Sair do Programa\n---------------------------------\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int numero;
                cout << "\nDigite o valor que deseja inserir na Fila: ";
                cin >> numero;
                cout << "\nO numero inserido na fila foi: " << numero<<endl;
                Pilha1.push(numero);
                break;

            case 2:
                desenfila();
                break;

            case 3:
                cout << "\nFim \n";
                break;

            default:
                cout << "\nOpcao invalida, digite uma opcao valida!\n";
                break;
        }
    }
}


#include <iostream>
#include <string>

using namespace std;

class Nopilha{
public:
    int info;
    Nopilha* prox;
};

class Nofila{
public:
    int info;
    Nofila* prox;
};

class Fila{
public:
    Nofila* inicio;
    Nofila* fim;
    int cont;

    void cria () {
        this->inicio = 0;
        this->fim = 0;
        cont = 0;
    }

    void enfila (int valor){
        auto* no = new Nofila{.info = valor,. prox = 0};
        if (cont==0){
            inicio=fim=no;
        }
        else{
            this->fim->prox = no;
            fim = no;
        }
        cont++;
    }

    void desenfila () {
        Nofila* no = inicio->prox;
        delete this->inicio;
        this->inicio = no;
        cont--;
    }
};

class Pilha{
public:
    Nopilha* inicio;
    int cont,cont2;

    void cria(){
    this->inicio = 0;
    cont = 0;
    cont2 = 0;
    }

    void empilha (int valor){
        auto* no = new Nopilha{.info = valor, .prox=this->inicio};
        this->inicio = no;
        cont++;
        cont2++;
    }

    void desempilha (){
        Nopilha* no = this->inicio->prox;
        delete this->inicio;
        this->inicio=no;
        cont--;
    }

    void topo (){
        if(cont==0){
          cout << "A pilha esta vazia";
        }
        else{
            cout<<" O topo e: " << this->inicio->info;
        }
    }
};

void inverte(auto* p1, auto* f1){
        int i;
        for (i=0;i<p1->cont2;i++){
            f1->enfila(p1->inicio->info);
            p1->desempilha();
        }

        for (i=0;i<p1->cont2;i++){
            p1->empilha(f1->inicio->info);
            cout << "\n" << i+1 <<" numero apos a inversao da pilha: " << p1->inicio-> info << endl;
            f1->desenfila();
        }
}

int main (){
    Pilha p;
    Fila f;

    f.cria();
    p.cria();

    p.empilha(1);
    p.empilha(2);
    p.empilha(3);

    inverte(&p,&f);

}

b)

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class noPilha{
    public:
        string info;
        noPilha* prox;
};

class pilha{
    public:
        int cont, n;
        noPilha* inicio;

        void cria(){
            cont = 0;
            inicio = 0;
            n = 0;
        }

        void empilha(string info){
            auto* no = new noPilha{.info = info, .prox = this -> inicio};
            this -> inicio = no;
            cont++;
            n++;
        }

        string desempilha(){
            string info = this -> inicio -> info;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont--;

            return info;
        }
};


class noFila{
    public:
        string info;
        noFila* prox;
};

class fila{
    public:
        int cont;
        noFila* inicio;
        noFila* fim;

        void cria(){
            cont = 0;
            inicio = 0;
            fim = 0;
        }

        void enfileira(string info){
            auto* no = new noFila{.info = info, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                fim -> prox = no;
                fim = no;
            }
            cont++;
        }

        void desenfileira(){
            auto info = inicio -> info;
            noFila* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont --;
        }
};

void copiaPilha(struct noPilha* pi, struct pilha* p, int cont, int n){
    if(cont == n){
        cont--;
        n--;
    } else {
        pi = pi->prox;
        cont++;
        copiaPilha(pi, p, cont, n);
        p->empilha(pi->info);
    }
}

int main(void){
    int i, j;
    pilha p1;
    pilha p2;
    pilha p3;
    pilha aux1;
    pilha aux2;
    pilha aux3;

    p1.cria();
    p2.cria();
    p3.cria();
    aux1.cria();
    aux2.cria();
    aux3.cria();

    fila f1;
    f1.cria();

    p1.empilha("1");
    p1.empilha("2");
    p1.empilha("3");
    p1.empilha("4");
    p1.empilha("5");

    p2.empilha("1");
    p2.empilha("2");
    p2.empilha("3");
    p2.empilha("4");
    p2.empilha("5");

    p3.empilha("1");
    p3.empilha("2");
    p3.empilha("3");
    p3.empilha("4");
    p3.empilha("5");

    //A troca de ordem de p1 será usando uma fila

    cout << "Pilha p1: ";
    for(i=0; i<p1.n; i++){
        f1.enfileira(p1.inicio->info);
        cout << p1.inicio -> info << " ";
        p1.desempilha();
    }

    for(i=0; i<p1.n; i++){
        p1.empilha(f1.inicio->info);
        f1.desenfileira();
        p1.n--;
    }
    
    cout << "\nPilha p1 invertida: ";
    for(i=0; i<p1.n; i++){
        cout << p1.inicio -> info << " ";
        p1.desempilha();
    }
    cout <<"\n\n";

    cout << "Pilha p2: ";
    for(i=0; i<p2.n; i++){
        aux1.empilha(p2.inicio->info);
        cout << p2.inicio->info << " ";
        p2.desempilha();
    }

    for(i=0; i<aux1.n; i++){
        aux2.empilha(aux1.inicio->info);
        aux1.desempilha();
    }

   
    for(i=0; i<aux2.n; i++){
        p2.empilha(aux2.inicio->info);
        aux2.desempilha();
    }

    noPilha* p;
    p = p2.inicio;
    cout << "\nPilha p2 invertida: ";
    while(p != 0){
        cout << p->info << " ";
        p = p->prox;
    }
    cout <<"\n";

    //A troca de ordem de p3 será usando uma pilha
    noPilha* pi;
    int k=p3.n - 1;
    int cont = 0;

    pi = p3.inicio;
    copiaPilha(pi,&aux3, cont, k);
    aux3.empilha(pi->info);

    cout << "\nPilha p3: ";
    for(i=0; i<p3.n; i++){
        cout << p3.desempilha() << " ";
    }

    p3.n=0;

    for(i=0; i<aux3.n; i++){
        p3.empilha(aux3.inicio->info);
        aux3.desempilha();
    }

    pi = p3.inicio;
    cout << "\nPilha p3 invertida: ";
    while(pi != 0){
        cout << pi->info << " ";
        pi = pi->prox;
    }
    cout << "\n\n";
}
Questão 5)
a)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class noPilha{
    public:
        string info;
        noPilha* prox;
};

class pilha{
    public:
        int cont, n;
        noPilha* inicio;

        void cria(){
            cont = 0;
            inicio = 0;
            n = 0;
        }

        void empilha(string info){
            auto* no = new noPilha{.info = info, .prox = this -> inicio};
            this -> inicio = no;
            cont++;
            n++;
        }

        string desempilha(){
            string info = this -> inicio -> info;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont--;

            return info;
        }
};


class noFila{
    public:
        string info;
        noFila* prox;
};

class fila{
    public:
        int cont, n;
        noFila* inicio;
        noFila* fim;

        void cria(){
            cont = 0;
            n = 0;
            inicio = 0;
            fim = 0;
        }

        void enfileira(string info){
            auto* no = new noFila{.info = info, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                fim -> prox = no;
                fim = no;
            }
            cont++;
            n++;
        }

        void desenfileira(){
            auto info = inicio -> info;
            noFila* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont --;
        }
};

void filaParaPilha(struct fila* f, struct pilha* p){
    if(f->cont == 0){
        return;
    } else {
        p->empilha(f->inicio->info);
        f->desenfileira();
        filaParaPilha(f,p);
    }
}

void pilhaParaFila(struct pilha* p, struct fila* f){
    if(p->cont == 0){
        return;
    } else {
        f->enfileira(p->inicio->info);
        p->desempilha();
        pilhaParaFila(p, f);
    }
}

void printFila(struct fila* f){
    noFila* fi;
    fi = f->inicio;
    while(fi != 0){
        cout << fi->info << " ";
        fi = fi->prox;
    }
}

int main(void){
    fila f1;
    fila aux1;
    fila aux2;

    pilha p1;

    f1.cria();
    aux1.cria();
    aux2.cria();

    p1.cria();  

    f1.enfileira("1");
    f1.enfileira("2");
    f1.enfileira("3");
    f1.enfileira("4");
    f1.enfileira("5");
    
    cout << "Fila f1: ";
    printFila(&f1);

    filaParaPilha(&f1, &p1);
    pilhaParaFila(&p1, &f1);

    cout << "\nFila f1 invertida: ";
    printFila(&f1);
    
    cout << "\n\n";
}
b)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class noPilha{
    public:
        string info;
        noPilha* prox;
};

class pilha{
    public:
        int cont, n;
        noPilha* inicio;

        void cria(){
            cont = 0;
            inicio = 0;
            n = 0;
        }

        void empilha(string info){
            auto* no = new noPilha{.info = info, .prox = this -> inicio};
            this -> inicio = no;
            cont++;
            n++;
        }

        string desempilha(){
            string info = this -> inicio -> info;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont--;

            return info;
        }
};


class noFila{
    public:
        string info;
        noFila* prox;
};

class fila{
    public:
        int cont, n;
        noFila* inicio;
        noFila* fim;

        void cria(){
            cont = 0;
            n = 0;
            inicio = 0;
            fim = 0;
        }

        void enfileira(string info){
            auto* no = new noFila{.info = info, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                fim -> prox = no;
                fim = no;
            }
            cont++;
            n++;
        }

        void desenfileira(){
            auto info = inicio -> info;
            noFila* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont --;
        }
};

void filaParaPilha(struct fila* f, struct pilha* p){
    if(f->cont == 0){
        return;
    } else {
        p->empilha(f->inicio->info);
        f->desenfileira();
        filaParaPilha(f,p);
    }
}

void pilhaParaFila(struct pilha* p, struct fila* f){
    if(p->cont == 0){
        return;
    } else {
        f->enfileira(p->inicio->info);
        p->desempilha();
        pilhaParaFila(p, f);
    }
}

void printFila(struct fila* f){
    noFila* fi;
    fi = f->inicio;
    while(fi != 0){
        cout << fi->info << " ";
        fi = fi->prox;
    }
}

int main(void){
    fila f1;
    fila aux1;
    fila aux2;

    pilha p1;

    f1.cria();
    aux1.cria();
    aux2.cria();

    p1.cria();  

    f1.enfileira("1");
    f1.enfileira("2");
    f1.enfileira("3");
    f1.enfileira("4");
    f1.enfileira("5");
    
    //Invertendo uma fila usando uma pilha
    cout << "Fila f1: ";
    printFila(&f1);

    filaParaPilha(&f1, &p1);
    pilhaParaFila(&p1, &f1);

    cout << "\nFila f1 invertida: ";
    printFila(&f1);
    
    cout << "\n\n";
Questão 6)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

template <typename tipo>
class noPilha{
    public:
        tipo info;
        noPilha* prox;
};

template <typename tipo>
class pilha{
    public:
        noPilha<tipo>* inicio;
        int cont, i;
        void cria(){
            inicio = 0;
            cont = 0;
        }
        void libera(){
            for(i=0; i<cont; i++){
                noPilha<tipo>* p = this -> inicio -> prox;
                delete this -> inicio;
                this -> inicio = p;
                cont--;
            }
        }
        void empilha(tipo info){
            auto* pi = new noPilha<tipo>{.info = info, .prox = inicio};
            inicio = pi;
            cont++;
        }
        void desempilha(){
            noPilha<tipo>* pi = this -> inicio -> prox;
            auto info = this -> inicio->info;
            delete this -> inicio;
            this -> inicio = pi;
            cont --;
        }
        int topo(){
            return this -> inicio ->info;
        }
    
};

template <typename tipo>
tipo pilhaMin(struct pilha<tipo>* p){
    noPilha<tipo>* pi = p->inicio;
    tipo minimo = pi->info;

    while(pi != 0){
        if(pi -> info < minimo){
            minimo = pi->info;
        }
        pi = pi->prox;
    }
    return minimo;
}

int main(void){
    pilha<int> p1;
    p1.cria();

    p1.empilha(5);
    p1.empilha(2);
    p1.empilha(3);

    cout << "\nO menor valor da pilha: " << pilhaMin(&p1) << "\n\n";

#include "../src/include/notacaoPolonesaReversa.hpp"
#include <assert.h>
#include <string.h>

int main () {

  assert(notacaoPolonesaReversa("((A+B)*(C-(F/D)))").compare("AB+CFD/-*"));
  
  assert(notacaoPolonesaReversa("").compare(""));

  assert(notacaoPolonesaReversa("(((A+B)*(C-(F/D)))").compare("Nao valido.")); 

  assert(notacaoPolonesaReversa("((A+B)*(C-(F/D))))").compare("Nao valido.")); 

  return 0;
}
