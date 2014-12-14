#ifndef CMOUVEMENT_H
#define CMOUVEMENT_H

#include <QString>

class CMouvement
{
public:
    CMouvement();

    void setNumcategorie(const QString &numcat) { m_numcategorie = numcat; }
    void setDate(const QString &date) { m_date = date; }
    void setNumcheque(const QString &numchq) { m_numcheque = numchq; }
    void setBeneficiaire(const QString &benef) { m_beneficiaire = benef; }
    void setDebit(const QString &debit) { m_debit = debit; }
    void setCredit(const QString &credit) { m_credit = credit; }

    QString numcategorie() const { return m_numcategorie; }
    QString date() const { return m_date; }
    QString numcheque() const { return m_numcheque; }
    QString beneficiaire() const { return m_beneficiaire; }
    QString debit() const { return m_debit; }
    QString credit() const { return m_credit; }

private:
    QString m_numcategorie;
    QString m_date;
    QString m_numcheque;
    QString m_beneficiaire;
    QString m_debit;
    QString m_credit;
};

#endif // CMOUVEMENT_H
