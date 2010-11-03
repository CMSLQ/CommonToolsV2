#!/bin/tcsh

# Put OptimizationPlot.C, CLA.C, and OptimizationJob.csh (make it executable) in the same directory and submit an lxbatch job
# bsub -q 8nh -o `pwd`/OptimizationJob.log OptimizationJob.csh

cd /afs/cern.ch/user/f/ferencek/scratch0/LQ/CMSSW_3_5_7/test/Leptoquarks/rootNtupleAnalyzerV2/data/output/LQ_M-320GeV_L-10pb_OPT_minMETPt1stEle_MTenu_ST/

eval `scramv1 runtime -csh`

root -l -q OptimizationPlot.C+\(1000\)

exit 0
