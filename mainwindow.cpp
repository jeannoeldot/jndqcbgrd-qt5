#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QSettings>
#include <QPrintDialog>
#include <QPrinter>

#include "mainwindow.h"

#include "miseaupoint.h"
#include "testretourcreationdlg.h"

#include "constantes.h"
//#include "cmouvement.h"
#include "ccompte.h"
#include "creationcomptedlg.h"
#include "previsionbudgetdlg.h"
#include "modificationnomdlg.h"
#include "entreesmouvementsdlg.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    m_fchoixfichier = false;
    m_fdonneesmodifiees = false;
    m_fdonneesimprimees = false;
    m_fdonneessauvees = false;

//    m_qlmouvement.clear();

    initialiserNomFichierChoisi("");
    m_strCheminFichierChoisi = QDir::homePath();

    initialiserOriginalCompte();

    m_posMainWin = QPoint(50, 50);

    m_fposCreationConnue = false;
    m_fposPrevisionConnue = false;
    m_fposEntreeMvtConnue = false;
    m_fposModificationConnue = false;

    readSettings();

    afficherBoutonsCompte(INITIALISER);

    setWindowTitle(NOM_PROG);
    setWindowIcon(QIcon(":/icones/IconeProg.png"));

    //La Date Du Jour
    QDate date = QDate::currentDate();
    m_datedujour = date.toString("dddd d MMMM yyyy");
    labelDateDuJour->setText(m_datedujour);
    m_dateImprimePdf = date.toString("yyyy-MM-dd");
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
    qDebug() << "Initialisation : date AAAA-MM-DD = " << m_dateImprimePdf;
#endif
///

//    QSize size = QSize(676, 442);
    QSize size = QSize(691, 660);
    setMinimumSize(size);
    setMaximumSize(size);
    resize(size);
    move(m_posMainWin);
}

void MainWindow::on_pbChoisirCompte_clicked()
{
    bool r = chargerFichier();
    if (true == r)
    {
        m_fdonneesmodifiees = false;
        m_fchoixfichier = true;
        m_fdonneesimprimees = false;
        m_fdonneessauvees = false;
        copierCompteOriginalToCopie();

        afficherBoutonsCompte(OUVRIR_COMPTE);

/// TODO : MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn ChoisirCompte - Lecture OK : nom fichier = " << m_strNomFichierChoisi;
        TestRetourCreationDlg test(m_copieCompte, m_strNomFichierChoisi, this);
        test.exec();
#endif
///
    }
    else
    {
        m_fdonneesmodifiees = false;
        m_fchoixfichier = false;
        m_fdonneesimprimees = false;
        m_fdonneessauvees = false;
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn ChoisirCompte - PAS de choix ou Lecture PAS OK !!!!!!! ";
#endif
///
    }
}

//bool m_fposCreationConnue;
//QPoint  m_posCreationDlg;
void MainWindow::on_pbCreerCompte_clicked()
{
    CreationCompteDlg dialog(this);
    if (true == m_fposCreationConnue)
    {
        dialog.move(m_posCreationDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        m_originalCompte = dialog.compteModified();
        m_fdonneesmodifiees = true;
        m_fchoixfichier = false;
        m_fdonneesimprimees = false;
        m_fdonneessauvees = false;
        initialiserNomFichierChoisi("");
        copierCompteOriginalToCopie();

        afficherBoutonsCompte(CREER_COMPTE);

        m_posCreationDlg = dialog.pos();
        m_fposCreationConnue = true;

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        TestRetourCreationDlg test(m_copieCompte, "Création Compte", this);
        test.exec();
#endif
///
    }
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
    else
    {
        qDebug() << "Creation Compte : Clic sur Annuler";
    }
#endif
///
}

void MainWindow::on_pbFermerCompte_clicked()
{
    /// @todo A FINIR
    /// @todo QUESTION SI FERMER SI m_fdonneesmodifiees == true
    ///

    QString msg = "";
    if(true == m_fdonneesmodifiees)
    {
        msg += " Des données ont été modifiées.\n";
        if(false == m_fdonneesimprimees)
        {
            msg += " => Les données ne sont pas imprimées.\n";
        }
        if(false == m_fdonneessauvees)
        {
            msg += " => Les données ne sont pas sauvegardées.\n";
        }
    }

    int reponse = QMessageBox::question (this, NOM_PROG_AFF + " - Fermer",
                                                " Fermer le compte ouvert ? \n\n" + msg,
                                                "Annuler",      /// index 0
                                                "Fermer"       /// index 1
                                                );

    switch (reponse)
    {
        case 0 :          /// Annuler
            break;
        case 1 :          /// Fermer
            m_fchoixfichier = false;
            m_fdonneesmodifiees = false;
            m_fdonneesimprimees = false;
            m_fdonneessauvees = false;

            //    m_qlmouvement.clear();

            initialiserNomFichierChoisi("");
            initialiserOriginalCompte();

            afficherBoutonsCompte(FERMER_COMPTE);


/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
            qDebug() << "fn FermerCompte : Fichier Choisi = " << m_strNomFichierChoisi;
#endif
///
            break;
    }
}

//bool m_fposPrevisionConnue;
//QPoint  m_posPrevisionDlg;
void MainWindow::on_pbEntrerRevenu_clicked()
{
    PrevisionBudgetDlg dialog(m_copieCompte, m_datedujour, this);
    if (true == m_fposPrevisionConnue)
    {
        dialog.move(m_posPrevisionDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        m_copieCompte = dialog.compteModified();
        m_strImpressionRevenu = dialog.chaineImprimable();
        m_fdonneesmodifiees = true;
        m_fdonneesimprimees = false;
        m_fdonneessauvees = false;

        afficherBoutonsCompte(ENTRER_REVENU);

        m_posPrevisionDlg = dialog.pos();
        m_fposPrevisionConnue = true;

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
                TestRetourCreationDlg test(m_copieCompte, m_strImpressionRevenu, this);
                test.exec();
#endif
        ///
    }
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        else
        {
            qDebug() << "Entrée Revenu et dépenses : Clic sur Annuler";
        }
#endif
///
}

//bool m_fposEntreeMvtConnue;
//QPoint  m_posEntreeMvtDlg;
void MainWindow::on_pbEntrerMouvements_clicked()
{
    EntreesMouvementsDlg dialog(m_copieCompte, m_datedujour, this);
    if (true == m_fposEntreeMvtConnue)
    {
        dialog.move(m_posEntreeMvtDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        m_copieCompte = dialog.compteModified();
        m_strImpressionMouvements = dialog.chaineImprimable();
        m_fdonneesmodifiees = true;
        m_fdonneesimprimees = false;
        m_fdonneessauvees = false;

        afficherBoutonsCompte(ENTRER_MOUVEMENT);

        m_posEntreeMvtDlg = dialog.pos();
        m_fposEntreeMvtConnue = true;

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
                TestRetourCreationDlg test(m_copieCompte, m_strImpressionMouvements, this);
                test.exec();
#endif
        ///
    }
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        else
        {
            qDebug() << "Entrées Mouvements : Clic sur Annuler";
        }
#endif
///

}

//bool m_fposModificationConnue;
//QPoint  m_posModificationDlg;
void MainWindow::on_pbModifierNom_clicked()
{
/// @todo A FINIR
///
///
    ModificationNomDlg dialog(m_copieCompte, this);
    if (true == m_fposModificationConnue)
    {
        dialog.move(m_posModificationDlg);
    }
    bool reponse = dialog.exec();
    if( true == reponse )
    {
        m_copieCompte = dialog.compteModified();
        m_fdonneesmodifiees = true;
        m_fdonneesimprimees = false;
        m_fdonneessauvees = false;

        afficherBoutonsCompte(MODIFIER_NOM);

        m_posModificationDlg = dialog.pos();
        m_fposModificationConnue = true;

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
                TestRetourCreationDlg test(m_copieCompte, "Modification Noms Catégorie", this);
                test.exec();
#endif
///
    }
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        else
        {
            qDebug() << "Modification Noms Catégorie : Clic sur Annuler";
        }
#endif
///
}

void MainWindow::on_pbImprimerSauver_clicked()
{
    if(true == m_fdonneesmodifiees)
    {
// SAUVEGARDE
        bool r = sauverFichier();
        if (true == r)
        {
            m_fdonneessauvees = true;
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
            qDebug() << "fn ImprimerSauver - Sauvegarde OK : nom fichier = " << m_strNomFichierChoisi;
#endif
///
        }
        else
        {
            m_fdonneessauvees = false;
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
            qDebug() << "fn ImprimerSauver - Sauvegarde PAS OK !!!!!!! ";
#endif
///
        }

// FAIT CHAINE IMPRESSION ENTETE
        m_strImpressionEntete = "Le " + m_datedujour + FINLIGNE;
        m_strImpressionEntete += FINLIGNE;
        m_strImpressionEntete += "Compte : " + m_strNomFichierChoisi + FINLIGNE;
        m_strImpressionEntete += FINLIGNE;

// FAIT CHAINE IMPRESSION BILAN
        m_strImpressionBilan = "BILAN APRÈS OPÉRATIONS SUR LE COMPTE :" + FINLIGNE;
        m_strImpressionBilan += FINLIGNE;
        m_strImpressionBilan += ESPACES9 + "CATEGORIES    " + ESPACES5 + "  BUDGET " + FINLIGNE;
        m_strImpressionBilan += FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie01() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie01() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie02() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie02() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie03() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie03() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie04() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie04() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie05() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie05() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie06() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie06() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie07() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie07() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie08() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie08() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie09() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie09() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie10() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie10() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie11() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie11() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie12() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie12() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie13() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie13() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie14() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie14() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie15() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie15() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie16() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie16() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie17() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie17() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie18() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie18() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie19() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie19() + FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomCategorie20() + ESPACES5;
        m_strImpressionBilan += m_copieCompte.montantCategorie20() + FINLIGNE;

        m_strImpressionBilan += FINLIGNE;
        m_strImpressionBilan += ESPACES9 + m_copieCompte.nomSolde() + ESPACE1;
        m_strImpressionBilan += m_copieCompte.montantSolde() + FINLIGNE;

        QString nompdf;
        QString titre;

// IMPRESSION REVENU ET MOUVEMENTS
        titre = "Revenu-Mouvements";
//        nompdf = m_strCheminFichierChoisi + "/" + m_strBasenameFichierChoisi + "-" + titre + "-" + m_dateImprimePdf + ".pdf";
        nompdf = m_strCheminFichierChoisi + "/" + m_dateImprimePdf + "-" + m_strBasenameFichierChoisi + "-" + titre + ".pdf";
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn ImprimerSauver Impression : nom fichier R M = " << nompdf;
#endif
///

        QPrinter printerRM(QPrinter::HighResolution);
        printerRM.setOutputFileName(nompdf);
        QPrintDialog printdlgRM(&printerRM, this);
        printdlgRM.setWindowTitle(tr("Impression Entrées Revenu et Mouvements"));
        if (printdlgRM.exec() == QDialog::Accepted)
        {
            QString strPage1;
            QTextDocument docpage1;

            strPage1 = m_strImpressionEntete;
            strPage1 += m_strImpressionRevenu;
            strPage1 += FINLIGNE;
            strPage1 += FINLIGNE;
            strPage1 += m_strImpressionMouvements;
            QFont monoRM("Linux Libertine Mono", 9);
            docpage1.setDefaultFont(monoRM);
            docpage1.setPlainText(strPage1);
            docpage1.print(&printerRM);

// IMPRESSION BILAN
            titre = "Bilan";
//            nompdf = m_strCheminFichierChoisi + "/" + m_strBasenameFichierChoisi + "-" + titre + "-" + m_dateImprimePdf + ".pdf";
            nompdf = m_strCheminFichierChoisi + "/" + m_dateImprimePdf + "-" + m_strBasenameFichierChoisi + "-" + titre + ".pdf";
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
            qDebug() << "fn ImprimerSauver Impression : nom fichier B = " << nompdf;
#endif
///

            QPrinter printerB(QPrinter::HighResolution);
            printerB.setOutputFileName(nompdf);
            QPrintDialog printdlgB(&printerB, this);
            printdlgB.setWindowTitle(tr("Impression Bilan"));
            if (printdlgB.exec() == QDialog::Accepted)
            {
                QString strPage2;
                QTextDocument docpage2;

                strPage2 = m_strImpressionEntete;
                strPage2 += FINLIGNE;
                strPage2 += m_strImpressionBilan;
                QFont monoB("Linux Libertine Mono", 12);
                monoB.setBold(true);
                docpage2.setDefaultFont(monoB);
                docpage2.setPlainText(strPage2);
                docpage2.print(&printerB);

                m_fdonneesimprimees = true;
            }
        }
    }

    if  (true == m_fdonneessauvees && true == m_fdonneesimprimees)
    {
        m_fdonneesmodifiees = false;

        afficherBoutonsCompte(SAUVER_IMPRIMER);

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn ImprimerSauver - bool m_fdonneesmodifiees = " << m_fdonneesmodifiees;
#endif
///
    }
}

void MainWindow::initialiserOriginalCompte()
{
    m_originalCompte.initialiserAZero();
}

void MainWindow::copierCompteOriginalToCopie()
{
    m_copieCompte = m_originalCompte;
}

void MainWindow::copierCompteCopieToOriginal()
{
    m_originalCompte = m_copieCompte;
}

void MainWindow::afficherBoutonsCompte(const ACTIONSCOMPTE actionrealisee)
{
    switch (actionrealisee) {
    case INITIALISER:
        pbChoisirCompte->setEnabled(true);
        pbCreerCompte->setEnabled(true);
        pbFermerCompte->setEnabled(false);

        pbEntrerRevenu->setEnabled(false);
        pbEntrerMouvements->setEnabled(false);
        pbModifierNom->setEnabled(false);
        pbImprimerSauver->setEnabled(false);

        initialiserAffichageCompte(false);
        break;
    case OUVRIR_COMPTE:
        pbChoisirCompte->setEnabled(false);
        pbCreerCompte->setEnabled(false);
        pbFermerCompte->setEnabled(true);

        pbEntrerRevenu->setEnabled(true);
        pbEntrerMouvements->setEnabled(true);
        pbModifierNom->setEnabled(true);
        pbImprimerSauver->setEnabled(false);

        initialiserAffichageCompte(true);
        break;
    case CREER_COMPTE:
        pbChoisirCompte->setEnabled(false);
        pbCreerCompte->setEnabled(false);
        pbFermerCompte->setEnabled(true);

        pbEntrerRevenu->setEnabled(true);
        pbEntrerMouvements->setEnabled(true);
        pbModifierNom->setEnabled(true);
        pbImprimerSauver->setEnabled(true);

        initialiserAffichageCompte(true);
        break;
    case FERMER_COMPTE:
        pbChoisirCompte->setEnabled(true);
        pbCreerCompte->setEnabled(true);
        pbFermerCompte->setEnabled(false);

        pbEntrerRevenu->setEnabled(false);
        pbEntrerMouvements->setEnabled(false);
        pbModifierNom->setEnabled(false);
        pbImprimerSauver->setEnabled(false);

        initialiserAffichageCompte(false);
        break;
    case ENTRER_REVENU:
        pbChoisirCompte->setEnabled(false);
        pbCreerCompte->setEnabled(false);
        pbFermerCompte->setEnabled(true);

        pbEntrerRevenu->setEnabled(false);
        pbEntrerMouvements->setEnabled(true);
        pbModifierNom->setEnabled(true);
        pbImprimerSauver->setEnabled(true);

        initialiserAffichageCompte(true);
        break;
    case ENTRER_MOUVEMENT:
        pbChoisirCompte->setEnabled(false);
        pbCreerCompte->setEnabled(false);
        pbFermerCompte->setEnabled(true);

        pbEntrerRevenu->setEnabled(false);
        pbEntrerMouvements->setEnabled(false);
        pbModifierNom->setEnabled(true);
        pbImprimerSauver->setEnabled(true);

        initialiserAffichageCompte(true);
        break;
    case MODIFIER_NOM:
        pbChoisirCompte->setEnabled(false);
        pbCreerCompte->setEnabled(false);
        pbFermerCompte->setEnabled(true);

//  Etats des boutons inchangés
//        pbEntrerRevenu->setEnabled(false);
//        pbEntrerMouvements->setEnabled(false);
        pbModifierNom->setEnabled(true);
        pbImprimerSauver->setEnabled(true);

        initialiserAffichageCompte(true);
        break;
    case SAUVER_IMPRIMER:
        pbChoisirCompte->setEnabled(false);
        pbCreerCompte->setEnabled(false);
        pbFermerCompte->setEnabled(true);

        pbEntrerRevenu->setEnabled(true);
        pbEntrerMouvements->setEnabled(true);
        pbModifierNom->setEnabled(true);
        pbImprimerSauver->setEnabled(false);

        initialiserAffichageCompte(true);
        break;
    default:
        break;
    }
}

void MainWindow::initialiserAffichageCompte(bool visible)
{
    if(true == visible)
    {
        QString titre = "Compte : " + m_strNomFichierChoisi;
        affichageGroupBox->setTitle(titre);
        initialiserLabelAffichageCompte(m_copieCompte);
        affichageGroupBox->setVisible(true);
    }
    else
    {
        affichageGroupBox->setVisible(false);
    }
}

void MainWindow::initialiserLabelAffichageCompte(const CCompte &compte)
{
    labelNom01->setText(compte.nomCategorie01());
    labelMontant01->setText(compte.montantCategorie01());
    labelNom02->setText(compte.nomCategorie02());
    labelMontant02->setText(compte.montantCategorie02());
    labelNom03->setText(compte.nomCategorie03());
    labelMontant03->setText(compte.montantCategorie03());
    labelNom04->setText(compte.nomCategorie04());
    labelMontant04->setText(compte.montantCategorie04());
    labelNom05->setText(compte.nomCategorie05());
    labelMontant05->setText(compte.montantCategorie05());
    labelNom06->setText(compte.nomCategorie06());
    labelMontant06->setText(compte.montantCategorie06());
    labelNom07->setText(compte.nomCategorie07());
    labelMontant07->setText(compte.montantCategorie07());
    labelNom08->setText(compte.nomCategorie08());
    labelMontant08->setText(compte.montantCategorie08());
    labelNom09->setText(compte.nomCategorie09());
    labelMontant09->setText(compte.montantCategorie09());
    labelNom10->setText(compte.nomCategorie10());
    labelMontant10->setText(compte.montantCategorie10());
    labelNom11->setText(compte.nomCategorie11());
    labelMontant11->setText(compte.montantCategorie11());
    labelNom12->setText(compte.nomCategorie12());
    labelMontant12->setText(compte.montantCategorie12());
    labelNom13->setText(compte.nomCategorie13());
    labelMontant13->setText(compte.montantCategorie13());
    labelNom14->setText(compte.nomCategorie14());
    labelMontant14->setText(compte.montantCategorie14());
    labelNom15->setText(compte.nomCategorie15());
    labelMontant15->setText(compte.montantCategorie15());
    labelNom16->setText(compte.nomCategorie16());
    labelMontant16->setText(compte.montantCategorie16());
    labelNom17->setText(compte.nomCategorie17());
    labelMontant17->setText(compte.montantCategorie17());
    labelNom18->setText(compte.nomCategorie18());
    labelMontant18->setText(compte.montantCategorie18());
    labelNom19->setText(compte.nomCategorie19());
    labelMontant19->setText(compte.montantCategorie19());
    labelNom20->setText(compte.nomCategorie20());
    labelMontant20->setText(compte.montantCategorie20());

    labelNomSolde->setText(compte.nomSolde());
    // Affiche montant Solde :
    QString strmntsolde = compte.montantSolde();
    double dmntsolde = 0.00;
    bool ok;
    dmntsolde = strmntsolde.toDouble(&ok);
    QPalette palette;
    QBrush brush;
    QBrush brushRouge(QColor(255, 0, 0, 255));   // Rouge
    QBrush brushNoir(QColor(0, 0, 0, 255));   // Noir
    brush = brushNoir;
    if (dmntsolde < 0.00)
    {
        brush = brushRouge;
    }
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    labelMontantSolde->setPalette(palette);
    labelMontantSolde->setText(compte.montantSolde());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QString msg = "";
    if(true == m_fdonneesmodifiees)
    {
        msg += " Des données ont été modifiées:\n";
        if(false == m_fdonneesimprimees)
        {
            msg += " => Les données ne sont pas imprimées.\n";
        }
        if(false == m_fdonneessauvees)
        {
            msg += " => Les données ne sont pas sauvegardées.\n";
        }
    }
    int reponse = QMessageBox::question (this, NOM_PROG_AFF + " - Quitter",
                                                " Quitter Gestion Revenu Dépenses ? \n\n" + msg,
                                                "Annuler",	/// index 0
                                                "Quitter"	/// index 1
                                                );

    switch (reponse)
    {
        case 0 :          /// Annuler
            event->ignore();
            break;
        case 1 :          /// Quitter
            writeSettings();
            event->accept();
            break;
    }
}

void MainWindow::initialiserNomFichierChoisi(const QString &nomfichier)
{
    m_strNomFichierChoisi = nomfichier;
//    labelNomFichier->setText(m_strNomFichierChoisi);
}

bool MainWindow::sauverFichier()
{
    QString nomfichier = QFileDialog::getSaveFileName(this,
                                                  NOM_PROG_AFF + " - Sauver les données",
                                                  m_strCheminFichierChoisi,
                                                  "Fichier Gestion Revenu Dépenses (*.grd)"
                                                  );
    if (nomfichier.isEmpty())
    {
        return false;
    }

    QString str = QFileInfo(nomfichier).fileName();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
    qDebug() << "fn sauverFichier() : Nom Fichier SI PAS .grd AVANT CORRECTION = " << str;
#endif
///
    if (!str.endsWith(".grd"))
    {
        nomfichier += ".grd";
    }
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
    qDebug() << "fn sauverFichier() : Nom Fichier SI PAS .grd APRES CORRECTION = " << nomfichier;
#endif
///

    bool r = ecrireFichier(nomfichier);
    if (true == r)
    {
        m_strCheminFichierChoisi = QFileInfo(nomfichier).path();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn sauverFichier() : Chemin Fichier Choisi = " << m_strCheminFichierChoisi;
#endif
///

        m_strBasenameFichierChoisi = QFileInfo(nomfichier).baseName();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn sauverFichier() : Basename Fichier Choisi = " << m_strBasenameFichierChoisi;
#endif
///

        QString s = QFileInfo(nomfichier).fileName();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn sauverFichier() : Nom Fichier Choisi = " << s;
#endif
///

        initialiserNomFichierChoisi(s);
        return true;
    }
    else
    {
        return false;
    }
}

bool MainWindow::chargerFichier()
{
    QString nomfichier = QFileDialog::getOpenFileName(this,
                                                  NOM_PROG_AFF + " - Ouvrir un compte",
                                                  m_strCheminFichierChoisi,
                                                  "Fichier Gestion Revenu Dépenses (*.grd)"
                                                  );
    if (nomfichier.isEmpty())
    {
        return false;
    }

    bool r = lireFichier(nomfichier);
    if (true == r)
    {
        m_strCheminFichierChoisi = QFileInfo(nomfichier).path();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn chargerFichier() : Chemin Fichier Choisi = " << m_strCheminFichierChoisi;
#endif
///

        m_strBasenameFichierChoisi = QFileInfo(nomfichier).baseName();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn chargerFichier() : Basename Fichier Choisi = " << m_strBasenameFichierChoisi;
#endif
///

        QString s = QFileInfo(nomfichier).fileName();
/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
        qDebug() << "fn chargerFichier() : Nom Fichier Choisi = " << s;
#endif
///

        initialiserNomFichierChoisi(s);
        return true;
    }
    else
    {
        return false;
    }
}

bool MainWindow::ecrireFichier(const QString &nomfichier)
{
    QFile file(nomfichier);
    if(true == file.exists())
    {
        file.remove();
    }
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, NOM_PROG_AFF,
                             QString("Écriture du fichier %1 impossible:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    out << m_copieCompte.nomCategorie01() << SEPARATEUR << m_copieCompte.montantCategorie01() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie02() << SEPARATEUR << m_copieCompte.montantCategorie02() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie03() << SEPARATEUR << m_copieCompte.montantCategorie03() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie04() << SEPARATEUR << m_copieCompte.montantCategorie04() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie05() << SEPARATEUR << m_copieCompte.montantCategorie05() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie06() << SEPARATEUR << m_copieCompte.montantCategorie06() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie07() << SEPARATEUR << m_copieCompte.montantCategorie07() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie08() << SEPARATEUR << m_copieCompte.montantCategorie08() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie09() << SEPARATEUR << m_copieCompte.montantCategorie09() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie10() << SEPARATEUR << m_copieCompte.montantCategorie10() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie11() << SEPARATEUR << m_copieCompte.montantCategorie11() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie12() << SEPARATEUR << m_copieCompte.montantCategorie12() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie13() << SEPARATEUR << m_copieCompte.montantCategorie13() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie14() << SEPARATEUR << m_copieCompte.montantCategorie14() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie15() << SEPARATEUR << m_copieCompte.montantCategorie15() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie16() << SEPARATEUR << m_copieCompte.montantCategorie16() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie17() << SEPARATEUR << m_copieCompte.montantCategorie17() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie18() << SEPARATEUR << m_copieCompte.montantCategorie18() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie19() << SEPARATEUR << m_copieCompte.montantCategorie19() << SEPARATEUR << endl;
    out << m_copieCompte.nomCategorie20() << SEPARATEUR << m_copieCompte.montantCategorie20() << SEPARATEUR << endl;

    out << m_copieCompte.nomSolde() << SEPARATEUR << m_copieCompte.montantSolde() << SEPARATEUR << endl;

    return true;
}

bool MainWindow::lireFichier(const QString &nomfichier)
{
    QFile file(nomfichier);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, NOM_PROG_AFF,
                             QString("Lecture du fichier %1 impossible:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }

/// @todo MIS POUR TEST
#ifdef MISE_AU_POINT
//    qDebug() << "ligne 01 = " << ligne; // ligne 01 =  "CATEGORIE 01  @10.00@"
//    qDebug() << "champs 01 = " << champs;   // champs 01 =  ("CATEGORIE 01  ", "10.00", "")
//    qDebug() << "nom = " << nom;
//    qDebug() << "montant = " << montant;
//    qDebug() << "nomCategorie01 = " << m_originalCompte.nomCategorie01();
//    qDebug() << "montantCategorie01 = " << m_originalCompte.montantCategorie01();
#endif
///

    QString ligne;
    QStringList champs;
    QString nom;
    QString montant;

    QTextStream in(&file);

    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie01(nom);
    m_originalCompte.setMontantCategorie01(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie02(nom);
    m_originalCompte.setMontantCategorie02(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie03(nom);
    m_originalCompte.setMontantCategorie03(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie04(nom);
    m_originalCompte.setMontantCategorie04(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie05(nom);
    m_originalCompte.setMontantCategorie05(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie06(nom);
    m_originalCompte.setMontantCategorie06(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie07(nom);
    m_originalCompte.setMontantCategorie07(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie08(nom);
    m_originalCompte.setMontantCategorie08(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie09(nom);
    m_originalCompte.setMontantCategorie09(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie10(nom);
    m_originalCompte.setMontantCategorie10(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie11(nom);
    m_originalCompte.setMontantCategorie11(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie12(nom);
    m_originalCompte.setMontantCategorie12(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie13(nom);
    m_originalCompte.setMontantCategorie13(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie14(nom);
    m_originalCompte.setMontantCategorie14(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie15(nom);
    m_originalCompte.setMontantCategorie15(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie16(nom);
    m_originalCompte.setMontantCategorie16(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie17(nom);
    m_originalCompte.setMontantCategorie17(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie18(nom);
    m_originalCompte.setMontantCategorie18(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie19(nom);
    m_originalCompte.setMontantCategorie19(montant);
    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomCategorie20(nom);
    m_originalCompte.setMontantCategorie20(montant);

    ligne = in.readLine();
    champs = ligne.split(SEPARATEUR);
    nom = champs.takeFirst();
    montant = champs.takeFirst();
    m_originalCompte.setNomSolde(nom);
    m_originalCompte.setMontantSolde(montant);

    return true;
}

//bool m_fposCreationConnue;
//bool m_fposPrevisionConnue;
//bool m_fposEntreeMvtConnue;
//bool m_fposModificationConnue;
//QPoint  m_posCreationDlg;
//QPoint  m_posPrevisionDlg;
//QPoint  m_posEntreeMvtDlg;
//QPoint  m_posModificationDlg;

void MainWindow::readSettings()
{
    QPoint pos;
    bool f;
    QSettings settings(ORGANISATION, "JNDQT5-" + NOM_PROG_AFF);
    pos = settings.value("positionMainWin", m_posMainWin).toPoint();
    m_posMainWin = pos;
    QString str = settings.value("cheminFichier", m_strCheminFichierChoisi).toString();
    m_strCheminFichierChoisi = str;

    f = settings.value("flagPositionCreationConnue", false).toBool();
    m_fposCreationConnue = f;
    pos = settings.value("positionCreationDlg", QPoint(0, 0)).toPoint();
    m_posCreationDlg = pos;
    f = settings.value("flagPositionPrevisionConnue", false).toBool();
    m_fposPrevisionConnue = f;
    pos = settings.value("positionPrevisionDlg", QPoint(0, 0)).toPoint();
    m_posPrevisionDlg = pos;
    f = settings.value("flagPositionEntreeMvtConnue", false).toBool();
    m_fposEntreeMvtConnue = f;
    pos = settings.value("positionEntreeMvtDlg", QPoint(0, 0)).toPoint();
    m_posEntreeMvtDlg = pos;
    f = settings.value("flagPositionModificationConnue", false).toBool();
    m_fposModificationConnue = f;
    pos = settings.value("positionModificationDlg", QPoint(0, 0)).toPoint();
    m_posModificationDlg = pos;
}

void MainWindow::writeSettings()
{
    QSettings settings(ORGANISATION, "JNDQT5-" + NOM_PROG_AFF);
    settings.setValue("positionMainWin", pos());
    settings.setValue("cheminFichier", m_strCheminFichierChoisi);
    settings.setValue("flagPositionCreationConnue", m_fposCreationConnue);
    settings.setValue("positionCreationDlg", m_posCreationDlg);
    settings.setValue("flagPositionPrevisionConnue", m_fposPrevisionConnue);
    settings.setValue("positionPrevisionDlg", m_posPrevisionDlg);
    settings.setValue("flagPositionEntreeMvtConnue", m_fposEntreeMvtConnue);
    settings.setValue("positionEntreeMvtDlg", m_posEntreeMvtDlg);
    settings.setValue("flagPositionModificationConnue", m_fposModificationConnue);
    settings.setValue("positionModificationDlg", m_posModificationDlg);
}

void MainWindow::on_pbAbout_clicked()
{
    QMessageBox::about(this, "À propos de " + NOM_PROG_AFF,
                        QString("<h2>%1 %2</h2>"
                                "<p><h3>Simple outil d'aide à la Gestion du Revenu"
                                "<p>et des Dépenses.</h3>"
                        "<p>Copyright %3."
                        "<p>Ce programme est distribué selon les termes de la GPL v3."
                        "<p>")
            .arg( NOM_PROG )
            .arg( VERSION_PROG )
            .arg( COPYRIGHT )
             );
}

void MainWindow::on_pbAboutQt_clicked()
{
    QMessageBox::aboutQt(this, tr("About Qt"));
}
