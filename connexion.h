#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

class connexion
{
private:

public:
connexion();
bool ouvrirconnexion();
void fermerconnexion();
QSqlDatabase db ;


};
namespace QDBLite {
    class BD : public connexion {};
}


#endif // CONNEXION_H
