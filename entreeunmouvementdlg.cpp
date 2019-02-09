//#include <QtGui/QRegExpValidator>
#include <QRegExpValidator>
#include "entreeunmouvementdlg.h"
#include "constantes.h"

EntreeUnMouvementDlg::EntreeUnMouvementDlg(const QString &nomcategorie, const QString &numerocategorie, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    labelNomCategorie->setText(nomcategorie);
    labelNumeroCategorie->setText(numerocategorie);

    QRegExp regExpDate("[0-9]{2,2}[/][0-9]{2,2}[/][0-9]{2,2}");
    lineEditDate->setValidator(new QRegExpValidator(regExpDate, this));
    lineEditDate->setPlaceholderText("01/08/16");

//    QRegExp regExpNumChq("[0-9A-Za-z]{1,6}");    // N'ACCEPTE PAS LES ESPACES
//    lineEditNumChq->setValidator(new QRegExpValidator(regExpNumChq, this));

//    QRegExp regExpBenef(".*");    // N'ACCEPTE PAS LES ESPACES
//    QRegExp regExpBenef("*");    // N'ACCEPTE PAS LES ESPACES
//    lineEditBenef->setValidator(new QRegExpValidator(regExpNumChq, this));

    QRegExp regExpMontant("[-|+][0-9]{1,5}[.][0-9]{2,2}");
    lineEditMontant->setValidator(new QRegExpValidator(regExpMontant, this));
}

//void EntreeUnMouvementDlg::reject()
//{
//    QDialog::reject();
//}

void EntreeUnMouvementDlg::accept()
{
//    lineEditDate->text();
    m_strChaineImprimable = formaterEntree(lineEditDate->text(), 8) + ESPACE1;
//    lineEditNumChq->text();
    m_strChaineImprimable += formaterEntree(lineEditNumChq->text(), 6) + ESPACE1;
//    lineEditBenef->text();
    m_strChaineImprimable += formaterEntree(lineEditBenef->text(), 40) + ESPACE1;

//    m_dMontant
//    lineEditMontant->text()
    if (m_dMontant < 0.00)
    {
        // débit
        m_strChaineImprimable += formaterMontant(lineEditMontant->text()) + ESPACE1;
        m_strChaineImprimable += ESPACES9;
    }
    else
    {
        // crédit
        m_strChaineImprimable += ESPACES9 + ESPACE1;
        m_strChaineImprimable += formaterMontant(lineEditMontant->text());
    }

    m_posDlg = pos();

    QDialog::accept();
}


void EntreeUnMouvementDlg::on_lineEditDate_textChanged(const QString &arg1)
{
    bool ok = lineEditDate->hasAcceptableInput();
    if(true == ok)
    {
        /// TEST VALIDITE DATE 31/12/XX
        QString str;
        int n;
        str = arg1.mid(0,2);
        n = str.toInt();
        if(n >= 1 && n <= 31)
        {
            str = arg1.mid(3,2);
            n = str.toInt();
            if(n >= 1 && n <= 12)
            {
                str = arg1.mid(6,2);
                n = str.toInt();
                if(n >= 14)
                {
                    lineEditNumChq->setPlaceholderText("6 cars");
                    lineEditNumChq->setEnabled(ok);
                }
            }
        }
    }
}

void EntreeUnMouvementDlg::on_lineEditNumChq_textChanged(const QString &arg1)
{
//    bool ok = lineEditNumChq->hasAcceptableInput();
//    if(true == ok)
//    {
//        lineEditBenef->setPlaceholderText("40 caractères maxi");
//        lineEditBenef->setEnabled(ok);
//    }
    if (arg1.length() >= 1)
    {
        lineEditBenef->setPlaceholderText("40 caractères maxi");
        lineEditBenef->setEnabled(true);
    }
}

void EntreeUnMouvementDlg::on_lineEditBenef_textChanged(const QString &arg1)
{
//    bool ok = lineEditBenef->hasAcceptableInput();
//    if(true == ok)
//    {
//        lineEditMontant->setPlaceholderText("+/-12345.67");
//        lineEditMontant->setEnabled(true);
//    }
    if (arg1.length() >= 1)
    {
        lineEditMontant->setPlaceholderText("+/-12345.67");
        lineEditMontant->setEnabled(true);
    }
}

void EntreeUnMouvementDlg::on_lineEditMontant_textChanged()
{
    bool mntok = lineEditMontant->hasAcceptableInput();
    if(true == mntok)
    {
        bool ok;
        QString str = lineEditMontant->text();
        double d = str.toDouble(&ok);
        if( true == ok )
        {
            m_dMontant = d;
            accepterButton->setEnabled(true);
        }
    }
}

QString EntreeUnMouvementDlg::formaterEntree(const QString &entree, const int nbcar)
{
    QString str = "";
    if (entree.length() < nbcar)
    {
        int nbespaces = nbcar - entree.length();
        str = entree;
        for (int i = 0; i < nbespaces; ++i)
        {
            str += " ";
        }
    }
    else
    {
        str = entree;
    }
    return str;
}

QString EntreeUnMouvementDlg::formaterMontant(const QString &montant)
{
    QString str = "";
    if (montant.length() < 9)
    {
        int nbespaces = 9 - montant.length();
        for (int i = 0; i < nbespaces; ++i)
        {
            str += " ";
        }
        str += montant;
    }
    else
    {
        str = montant;
    }
    return str;
}
