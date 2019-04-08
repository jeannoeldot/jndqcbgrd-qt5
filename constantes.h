#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <QString>

const QString VERSION_PROG = "0.2.1";
const QString NOM_PROG = "Gestion Revenu Dépenses";
const QString NOM_PROG_AFF = "G.R.D.";
const QString ORGANISATION = "JND-Software";
const QString COPYRIGHT = "2014-2019 JND-Software Inc";

const QString SEPARATEUR = "@";
const QString SIGNE_PLUS = "+";

const QString FINLIGNE = "\n";
const QString ESPACE1 = " ";
const QString ESPACESX = "123456789";
const QString ESPACES3 = "   ";
const QString ESPACES5 = "     ";
const QString ESPACES9 = "         ";

enum ACTIONSCOMPTE {INITIALISER, OUVRIR_COMPTE, CREER_COMPTE, FERMER_COMPTE,
                   ENTRER_REVENU, ENTRER_MOUVEMENT, MODIFIER_NOM, SAUVER_IMPRIMER};

#endif // CONSTANTES_H
