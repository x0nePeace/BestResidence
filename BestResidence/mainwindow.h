#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setTypeAnnonce(QString);
    void setTypeBien(QString);
    void setNbPieces(int);
    void setSuperficie(double);
    void setAdresse(QString);
    void setVille(QString);
    void setCodePostal(QString);
    void setDescription(QString);
    void setDate(QString);
    void setPrix(double);
    void setPhotoPrincipale(QString);
    void setPhotosSupp(QString[]);
    void setAnnule(bool);
    void setHisto(int);
    QString annonces[1000][22];
    QString clients[1000][12];
    QString aff_annonces_vente[1000][22];
    QString aff_annonces_location[1000][22];
    QString aff_histo_vente[1000][22];
    QString aff_histo_location[1000][22];
    int nb_annonces = 0;
    int nb_clients = 0;
    int nb_aff_annonces_vente = 0;
    int nb_aff_annonces_location = 0;
    int nb_aff_histo_vente = 0;
    int nb_aff_histo_location = 0;
    void addTabAnnoncesVente();
    void addTabAnnoncesLocation();
    void addTabHistoVente();
    void addTabHistoLocation();
    void addTabClients();
    void initAnnonces();

private slots:
    void on_pushButton_clicked();
    void on_tableOffreVente_clicked(const QModelIndex &index);
    void on_tableOffreLocation_clicked(const QModelIndex &index);
    void on_tableBienVendu_clicked(const QModelIndex &index);
    void on_tableBienLoue_clicked(const QModelIndex &index);

private:
    void readXmlFile();
    void writeXmlFile();
    Ui::MainWindow *ui;
    QDomDocument *dom;
    QString typeAnnonce;
    QString typeBien;
    int nbPieces;
    double superficie;
    QString adresse;
    QString ville;
    QString codePostal;
    QString description;
    double prix;
    QString photoPrincipale;
    QString photosSupp[8];
    QString date;
    bool annule;
    int histo;

    QTableWidgetItem* wdg_photo;
    QTableWidgetItem* wdg_bien;
    QTableWidgetItem* wdg_pieces;
    QTableWidgetItem* wdg_superficie;
    QTableWidgetItem* wdg_ville;
    QTableWidgetItem* wdg_prix;
    QTableWidgetItem* wdg_date;
    QTableWidgetItem* wdg_id_client;
    QTableWidgetItem* wdg_nom;
    QTableWidgetItem* wdg_prenom;
    QTableWidgetItem* wdg_courriel;
    QTableWidgetItem* wdg_telephone;
};

#endif // MAINWINDOW_H
