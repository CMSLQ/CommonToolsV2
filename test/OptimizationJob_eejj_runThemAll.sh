#!/bin/bash

SAMPLES='LQeejj_M250 LQeejj_M280 LQeejj_M300 LQeejj_M320 LQeejj_M340 LQeejj_M370 LQeejj_M400 LQeejj_M450 LQeejj_M500'

usage ()
{
        echo "Usage:   $0 -r      (in order to run on the following samples: $SAMPLES)"
        echo "Usage:   $0 -c      (to cleanup files .sh and .C created by this script)"
        exit 1;
}


if [ $# != 1 ]; then
    usage
fi

if [ $1 == '-r' ]; then
    for SAMPLE in $SAMPLES
      do
      cp OptimizationPlot_eejj.C OptimizationPlot_eejj_${SAMPLE}.C
      perl -pi -e 's|'LQeejj_M[0-9][0-9]0'|'${SAMPLE}'|g' OptimizationPlot_eejj_${SAMPLE}.C
      perl -pi -e 's|'OptimizationPlot_eejj'|'OptimizationPlot_eejj_${SAMPLE}'|g' OptimizationPlot_eejj_${SAMPLE}.C
      
      cp OptimizationJob_eejj.sh OptimizationJob_eejj_${SAMPLE}.sh
      perl -pi -e 's|'OptimizationPlot_eejj.C'|'OptimizationPlot_eejj_${SAMPLE}.C'|g' OptimizationJob_eejj_${SAMPLE}.sh
      
      bsub -q 8nh -o `pwd`/OptimizationJob_eejj_${SAMPLE}.log OptimizationJob_eejj_${SAMPLE}.sh
    done
fi

if [ $1 == '-c' ]; then
    # cleanup
    # sleep 10 # wait to make sure all jobs have started
    for SAMPLE in $SAMPLES
      do
      rm OptimizationPlot_eejj_${SAMPLE}.C OptimizationJob_eejj_${SAMPLE}.sh OptimizationPlot_eejj_${SAMPLE}_C.so
    done
fi


