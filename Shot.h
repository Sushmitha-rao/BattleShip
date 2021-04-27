/*
 * Shot.h
 *
 *  Created on: Dec 7, 2019
 *      Author: Sushmitha
 */

#ifndef SHOT_H_
#define SHOT_H_

#include"GridPosition.h"

/**
 * \brief This class represents a shot on the position in a grid
 *
 * This class has public data member that represents whether the shot is missed or hit
 * It has a public getter function to get the target position
 *
 * \author	Sushmitha
 * \version 1.0
 * \date DEC-2019
 */
class Shot
{
	private:

	/**
	 * This private data member represents the target position
	 */
	GridPosition targetPosition;
public:

	/**
	 * This constructor initializes the target position with specified value
	 * @param targetPosition: represents the target position to be hit
	 */
	Shot(GridPosition targetPosition);

	/**
	 * This public getter function gets the target position
	 * @return the target position
	 */
	GridPosition getTargetPosition();

	/**
	 * This public data member represents the status of a shot
	 */
	enum Impact
	{
		/**0*/
		NONE,

		/**1*/
		HIT,

		/**2*/
		SUNKEN

	} shotImpact;

};

#endif /* SHOT_H_ */
