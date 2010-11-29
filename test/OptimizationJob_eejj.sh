#!/bin/sh

# Put OptimizationPlot_eejj.C, cl95cms.C, and OptimizationJob_eejj.sh (make it executable) in the same directory and submit an lxbatch job
# bsub -q 8nh -o `pwd`/OptimizationJob_eejj.log OptimizationJob_eejj.sh

cd /afs/cern.ch/user/p/prumerio/cms/lq/CMSSW_3_5_7/src
eval `scramv1 runtime -sh`

cd /afs/cern.ch/user/p/prumerio/cms/lq/opt_eejj/CommonToolsV2/test
root -l -q OptimizationPlot_eejj.C+\(100\)

exit 0
