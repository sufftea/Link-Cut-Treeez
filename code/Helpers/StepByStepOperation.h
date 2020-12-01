#ifndef STEPBYSTEPOPERATION_H
#define STEPBYSTEPOPERATION_H

/*
 * Inherit a class for an operation from this class and implement
 * make_step() function for that operation
 *
 * make_step() must return 0 if the operation has just finished
 * and 1 otherwise.
 *
 * All the functions, exept for make_step() should be private
 */
class StepByStepOperation
{
public:
    StepByStepOperation() {}
    virtual ~StepByStepOperation() {}

    // must return 0 if the operation has just finished, 1 otherwise.
    virtual bool make_step()=0;
};

#endif // STEPBYSTEPOPERATION_H
