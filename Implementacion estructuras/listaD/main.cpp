#include <iostream>
#include "listD.h"
#include <stdio.h>
#include <fstream>
using namespace std;





void load_reg(string file,ListD <Reg*> *my_list)
{
    FILE *loadFile;
    loadFile = fopen(file.c_str() , "rb");
    string pos_temp;
    string index_w;
    while(!feof(loadFile))
    {
        char ch_temp=fgetc(loadFile);
        if(isdigit(ch_temp))
            pos_temp.push_back(ch_temp);
        if(isalpha(ch_temp))
            index_w.push_back(ch_temp);
        if(ch_temp=='\n')
        {
            Reg * newReg=new Reg;
            newReg->index_w=index_w;
            newReg->pos_i= atoi(pos_temp.c_str());
            my_list->LpushBack(newReg);
            pos_temp="";
            index_w="";

        }
    }
    fclose(loadFile);
}

/*
void update(ListD<Reg *> & list_reg,string file)
{
    FILE * pFile;
    pFile = fopen ( file.c_str() , "rb" );
    fseek (pFile, 0, SEEK_END);
    size=ftell (pFile);

    for(int i=0;!feof(pFile);i++)
    {
        fseek ( pFile ,i,0);

        fgets(my_string,37,pFile);
        cout<<my_string<<endl;

        Reg *new_reg=new Reg;
        new_reg->pos_i=size;
        new_reg->index_w=word;
    }

    fclose ( pFile );
    return new_reg;


}

*/


int main()
{
/*
ListD<int> asd,asd1;
asd>>0>>6>>5>>4;
asd.print();

asd1>>1>>2>>3>>4>>5>>6>>7;
asd1.print();

auto lista=asd1+asd;
lista->print();

auto lista2=asd1-asd;
lista2->print();

cout<<"----------"<<endl;
asd.sort();
cout<<asd;

cout<<"-> "<<asd1.Lfind(4)<<endl;


asd.reverse();
asd.print();
*/

    ListD<Reg *> asd;

/*
    asd.LpushBack(asd.add_def("example.txt","A"," Primera letra del abecedario."));
    asd.LpushBack(asd.add_def("example.txt","B"," Segunda letra del abecedario."));
    asd.LpushBack(asd.add_def("example.txt","C"," Tercera letra del abecedario."));
    asd.LpushBack(asd.add_def("example.txt","D"," Cuarta letra del abecedario."));
*/
    //load_reg("load.txt",&asd);
   // cout<<(asd[0])->index_w;

    // asd.index("example.txt",0);
   // cout<<asd.m_begin->getDato()->index_w<<endl;
   //} cout<<asd.m_begin->getDato()->pos_i<<endl;


    return 0;
}

