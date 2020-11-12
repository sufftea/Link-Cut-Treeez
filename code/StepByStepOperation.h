#ifndef STEPBYSTEPOPERATION_H
#define STEPBYSTEPOPERATION_H

/*
 * Since I want to be able to animate any operation step-by-step,
 * I decided to create an object for each operation that stores
 * all the temporarry variables and has the only public function
 * make_step()
 *
 * Inherit an object for an operation from this class, implement
 * make_step() function
 *
 * All the functions, exept for make_step() should be in private
 * field
 */
class StepByStepOperation
{
public:
    StepByStepOperation() {}
    virtual ~StepByStepOperation() {}

    // must return 0 if the operation have just finished, 1 otherwise.
    virtual bool make_step()=0;
};

#endif // STEPBYSTEPOPERATION_H
