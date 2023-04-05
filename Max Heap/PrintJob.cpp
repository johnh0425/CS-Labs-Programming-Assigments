#include "PrintJob.h"

PrintJob::PrintJob ( int setP, int setJ, int numP ):priority(setP), jobNumber(setJ), numPages(numP){}       //constructor for Printjob
int PrintJob::getPriority ( ){
    return priority;                // returns the priority of PrintJob
}

int PrintJob::getJobNumber ( ){
    return jobNumber;               // returns the job Number of PrintJob
}

int PrintJob::getPages ( ){
    return numPages;                // returns the number of pages of PrintJob
}