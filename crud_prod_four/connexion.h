#ifndef CONNEXION_H
#define CONNEXION_H
#include <QtSql/QSqlDatabase>
class connexion
{
private:
  QSqlDatabase db ;
public:
connexion();
bool ouvrirconnexion();
void fermerconnexion();

};
#endif // CONNEXION_H
