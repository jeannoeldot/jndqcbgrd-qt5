#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

//#include "cmouvement.h"
#include "constantes.h"
#include "ccompte.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void on_pbChoisirCompte_clicked();

    void on_pbCreerCompte_clicked();

    void on_pbFermerCompte_clicked();

    void on_pbEntrerRevenu_clicked();

    void on_pbEntrerMouvements_clicked();

    void on_pbModifierNom_clicked();

    void on_pbImprimerSauver_clicked();

    void on_pbAbout_clicked();

    void on_pbAboutQt_clicked();

private:
    void readSettings();
    void writeSettings();
    void initialiserOriginalCompte();
    void copierCompteOriginalToCopie();
    void copierCompteCopieToOriginal();
    void initialiserNomFichierChoisi(const QString &nomfichier);
    bool sauverFichier();
    bool chargerFichier();
    bool ecrireFichier(const QString &nomfichier);
    bool lireFichier(const QString &nomfichier);

    void initialiserAffichageCompte(bool visible);
    void initialiserLabelAffichageCompte(const CCompte &compte);

    void afficherBoutonsCompte(const ACTIONSCOMPTE actionrealisee);

/// VARIABLES

    QPoint m_posMainWin;

    bool m_fposCreationConnue;
    bool m_fposPrevisionConnue;
    bool m_fposEntreeMvtConnue;
    bool m_fposModificationConnue;
    QPoint  m_posCreationDlg;
    QPoint  m_posPrevisionDlg;
    QPoint  m_posEntreeMvtDlg;
    QPoint  m_posModificationDlg;

    bool m_fchoixfichier;
    bool m_fdonneesmodifiees;
    bool m_fdonneesimprimees;
    bool m_fdonneessauvees;

    CCompte m_originalCompte;
    CCompte m_copieCompte;

    QString m_datedujour;
    QString m_dateImprimePdf;

    QString m_strNomFichierChoisi;
    QString m_strBasenameFichierChoisi;
    QString m_strCheminFichierChoisi;

    QString m_strImpressionRevenu;
    QString m_strImpressionMouvements;
    QString m_strImpressionBilan;
    QString m_strImpressionEntete;

//    QList<CMouvement> m_qlmouvement;

protected:
    void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
