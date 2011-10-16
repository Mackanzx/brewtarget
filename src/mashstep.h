/*
 * mashstep.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009-2011.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MASHSTEP_H
#define _MASHSTEP_H

#include <QDomNode>
#include "BeerXMLElement.h"
#include <QStringList>
#include <QString>

class MashStep;

class MashStep : public BeerXMLElement
{
   Q_OBJECT
public:

   enum Type {TYPEINFUSION, TYPETEMPERATURE, TYPEDECOCTION};

   MashStep();
   MashStep( MashStep const& other );

   virtual ~MashStep() {}

   virtual void toXml(QDomDocument& doc, QDomNode& parent); // From BeerXMLElement

   Q_PROPERTY( QString name READ name WRITE setName NOTIFY changed /*changedName*/ )
   Q_PROPERTY( Type type READ type WRITE setType NOTIFY changed /*changedType*/ )
   Q_PROPERTY( double infuseAmount_l READ infuseAmount_l WRITE setInfuseAmount_l NOTIFY changed /*changedInfuseAmount_l*/ )
   Q_PROPERTY( double stepTemp_c READ stepTemp_c WRITE setStepTemp_c NOTIFY changed /*changedStepTemp_c*/ )
   Q_PROPERTY( double stepTime_min READ stepTime_min WRITE setStepTime_min NOTIFY changed /*changedStepTime_min*/ )
   Q_PROPERTY( double rampTime_min READ rampTime_min WRITE setRampTime_min NOTIFY changed /*changedRampTime_min*/ )
   Q_PROPERTY( double endTemp_c READ endTemp_c WRITE setEndTemp_c NOTIFY changed /*changedEndTemp_c*/ )
   Q_PROPERTY( double infuseTemp_c READ infuseTemp_c WRITE setInfuseTemp_c NOTIFY changed /*changedInfuseTemp_c*/ )
   Q_PROPERTY( double decoctionAmount_l READ decoctionAmount_l WRITE setDecoctionAmount_l NOTIFY changed /*changedDecoctionAmount_l*/ )
   
   void setName( const QString &var );
   void setType( Type t );
   void setInfuseAmount_l( double var );
   void setStepTemp_c( double var );
   void setStepTime_min( double var );
   void setRampTime_min( double var );
   void setEndTemp_c( double var );
   void setInfuseTemp_c( double var );
   void setDecoctionAmount_l( double var );
   
   QString name() const;
   Type type() const;
   const QString& typeString() const;
   //! Returns a translated type string.
   const QString typeStringTr() const;
   double infuseAmount_l() const;
   double stepTemp_c() const;
   double stepTime_min() const;
   double rampTime_min() const;
   double endTemp_c() const;
   double infuseTemp_c() const;
   double decoctionAmount_l() const;

signals:
   /*
   void changedName(QString);
   void changedType(Type);
   void changedInfuseAmount_l(double);
   void changedStepTemp_c(double);
   void changedStepTime_min(double);
   void changedRampTime_min(double);
   void changedEndTemp_c(double);
   void changedInfuseTemp_c(double);
   void changedDecoctionAmount_l(double);
   */
   
private:
   bool isValidType( const QString &str ) const;
   static QStringList types;
};

inline bool MashStepPtrLt( MashStep* lhs, MashStep* rhs)
{
   return *lhs < *rhs;
}

inline bool MashStepPtrEq( MashStep* lhs, MashStep* rhs)
{
   return *lhs == *rhs;
}

struct MashStep_ptr_cmp
{
   bool operator()( MashStep* lhs, MashStep* rhs)
   {
      return *lhs < *rhs;
   }
};

struct MashStep_ptr_equals
{
   bool operator()( MashStep* lhs, MashStep* rhs )
   {
      return *lhs == *rhs;
   }
};

#endif //_MASHSTEP_H
