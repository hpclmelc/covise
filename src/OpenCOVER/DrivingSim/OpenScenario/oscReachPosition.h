/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl-2.1.txt.

* License: LGPL 2+ */
#ifndef OSC_REACH_POSITION_H
#define OSC_REACH_POSITION_H
#include <oscExport.h>
#include <oscObjectBase.h>
#include <oscObjectVariable.h>
#include <oscVariables.h>
#include <oscPosition.h>

namespace OpenScenario {

class OPENSCENARIOEXPORT conditionsType: public oscEnumType
{
public:
    static conditionsType *instance(); 
private:
    conditionsType();
    static conditionsType *inst;
};

/// \class This class represents a generic OpenScenario Object
class OPENSCENARIOEXPORT oscReachPosition: public oscObjectBase
{
public:

    enum conditions
    {
        exceed,
        deceed,
    };
    oscReachPosition()
    {
		OSC_OBJECT_ADD_MEMBER(position, "oscPosition");
		OSC_ADD_MEMBER(tolerance);
		OSC_ADD_MEMBER(conditions);
		conditions.enumType = conditionsType::instance();
    };
	
	oscPositionMember position;
	oscDouble tolerance;
	oscEnum conditions;
};

typedef oscObjectVariable<oscReachPosition *> oscReachPositionMember;

}

#endif //OSC_REACH_POSITION_H
