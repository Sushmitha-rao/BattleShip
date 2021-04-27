/*
 * Shot.cpp
 *
 *  Created on: Dec 7, 2019
 *      Author: Sushmitha
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPosition)
{
	this->targetPosition=targetPosition;
	 shotImpact=NONE;
}

GridPosition Shot::getTargetPosition()
{
	return targetPosition;
}

