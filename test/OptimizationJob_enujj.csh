#!/bin/tcsh

# Put OptimizationPlot_enujj.C, CLA.C, and OptimizationJob_enujj.csh (make it executable) in the same directory and submit an lxbatch job
# bsub -q 8nh -o `pwd`/OptimizationJob_enujj.log OptimizationJob_enujj.csh

cd /afs/cern.ch/user/f/ferencek/scratch0/LQ/CMSSW_3_5_7/test/Leptoquarks/rootNtupleAnalyzerV2/data/output/OPT_L_30pb-1_MLQ_200GeV/minMETPt1stEle_MTenu_ST/

eval `scramv1 runtime -csh`

root -l -q OptimizationPlot_enujj.C+\(1000\)

exit 0
