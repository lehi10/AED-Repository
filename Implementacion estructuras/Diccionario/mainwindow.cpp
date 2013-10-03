#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listD.h"
#include <QTableWidgetItem>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool flag=false;
ListD<Reg *> registro;


void ordenar(ListD<Reg*> *&ListReg)
{
    for(int i=0;i<ListReg->Lsize();i++)
    {
        nodoD<Reg*> *it= ListReg->m_begin;
        while(it->get_Nnext())
        {
            if(*(it->getDato()->index_w.begin()) > *((it->get_Nnext()->getDato())->index_w.begin()) )
            {
                Reg *temp= it->getDato();
                it->set_dat(it->get_Nnext()->getDato());
                it->get_Nnext()->set_dat(temp);
            }
            it=it->get_Nnext();
        }
    }
}

void ordenar_reg()
{
    ListD<Reg *> *ptr_re=&registro;
    ordenar(ptr_re);
}

void load_reg(string file,ListD <Reg*> *my_list)
{
    flag =true;
    FILE *loadFile;

    loadFile = fopen(file.c_str() , "rb");
    string pos_temp;
    string index_w;
    if (loadFile==NULL)
    {

        QWidget * _ventana = new QWidget();
        QLabel * _aviso = new QLabel("Diccionario vacio \n Don´t found Files");
        QVBoxLayout * _vertical_latout = new QVBoxLayout();
        _vertical_latout->addWidget(_aviso);
        _ventana->setLayout(_vertical_latout);
        _ventana->setWindowTitle("Error");
        _ventana->show();
        return;

    }

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

void MainWindow::on_pushButton_2_clicked()
{
    if(flag==false)
    {
        load_reg("load.txt",&registro);
        ordenar_reg();

    }
    ui->Lista->setRowCount(registro.Lsize());
    for(int i=0;i<registro.Lsize();i++)
    {
        QTableWidgetItem *item=new QTableWidgetItem;
        item->setText(QString((registro[i]->index_w).c_str()));
        ui->Lista->setItem(0,i,item);
    }
}

void MainWindow::on_buscar_clicked()
{
    int pos=registro[ui->Lista->currentRow()]->pos_i;
    ui->significado->setText(QString(registro.index("example.txt",pos).c_str()));
}

void MainWindow::on_agregar_clicked()
{
    if(ui->nueva_definicion->text()!= "" && ui->nueva_palabra->text()!="")
    {
        registro.LpushBack(registro.add_def("example.txt",ui->nueva_palabra->text().toStdString().c_str(),ui->nueva_definicion->text().toStdString().c_str()));
        ordenar_reg();
        on_pushButton_2_clicked();
        return;
    }
    if(ui->nueva_definicion->text()!= "" || ui->nueva_palabra->text()!="")
    {
        QWidget * _ventana = new QWidget();
        QLabel * _aviso = new QLabel(tr("Datos incompletos"));
        QVBoxLayout * _vertical_latout = new QVBoxLayout();
        _vertical_latout->addWidget(_aviso);
        _ventana->setLayout(_vertical_latout);
        _ventana->setWindowTitle("Error");
        _ventana->show();
    }
}

