#ifndef TESTRETOURCREATIONDLG_H
#define TESTRETOURCREATIONDLG_H

#include "ui_testretourcreationdlg.h"

#include "ccompte.h"
class CCompte;

class TestRetourCreationDlg : public QDialog, private Ui::TestRetourCreationDlg
{
    Q_OBJECT

public:
    explicit TestRetourCreationDlg(const CCompte &compte, const QString &texte, QWidget *parent = 0);
private:
    void initialiserLabel(const CCompte &compte);
    void initialiserTextEdit(const QString &texte);

    CCompte m_Compte;
    QString m_strTextEdit;

};

#endif // TESTRETOURCREATIONDLG_H
