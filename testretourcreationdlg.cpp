#include "testretourcreationdlg.h"

#include "ccompte.h"

TestRetourCreationDlg::TestRetourCreationDlg(const CCompte &compte, const QString &texte, QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    m_Compte = compte;
    m_strTextEdit = texte;

    initialiserLabel(m_Compte);
    initialiserTextEdit(m_strTextEdit);
}

void TestRetourCreationDlg::initialiserTextEdit(const QString &texte)
{
    textEdit->append(texte);
}

void TestRetourCreationDlg::initialiserLabel(const CCompte &compte)
{
    labelNomCat01->setText(compte.nomCategorie01());
    labelMontantCat01->setText(compte.montantCategorie01());

    labelNomCat02->setText(compte.nomCategorie02());
    labelMontantCat02->setText(compte.montantCategorie02());

    labelNomCat03->setText(compte.nomCategorie03());
    labelMontantCat03->setText(compte.montantCategorie03());

    labelNomCat04->setText(compte.nomCategorie04());
    labelMontantCat04->setText(compte.montantCategorie04());

    labelNomCat05->setText(compte.nomCategorie05());
    labelMontantCat05->setText(compte.montantCategorie05());

    labelNomCat06->setText(compte.nomCategorie06());
    labelMontantCat06->setText(compte.montantCategorie06());

    labelNomCat07->setText(compte.nomCategorie07());
    labelMontantCat07->setText(compte.montantCategorie07());

    labelNomCat08->setText(compte.nomCategorie08());
    labelMontantCat08->setText(compte.montantCategorie08());

    labelNomCat09->setText(compte.nomCategorie09());
    labelMontantCat09->setText(compte.montantCategorie09());

    labelNomCat10->setText(compte.nomCategorie10());
    labelMontantCat10->setText(compte.montantCategorie10());

    labelNomCat11->setText(compte.nomCategorie11());
    labelMontantCat11->setText(compte.montantCategorie11());

    labelNomCat12->setText(compte.nomCategorie12());
    labelMontantCat12->setText(compte.montantCategorie12());

    labelNomCat13->setText(compte.nomCategorie13());
    labelMontantCat13->setText(compte.montantCategorie13());

    labelNomCat14->setText(compte.nomCategorie14());
    labelMontantCat14->setText(compte.montantCategorie14());

    labelNomCat15->setText(compte.nomCategorie15());
    labelMontantCat15->setText(compte.montantCategorie15());

    labelNomCat16->setText(compte.nomCategorie16());
    labelMontantCat16->setText(compte.montantCategorie16());

    labelNomSolde->setText(compte.nomSolde());
    labelMontantSolde->setText(compte.montantSolde());
}
