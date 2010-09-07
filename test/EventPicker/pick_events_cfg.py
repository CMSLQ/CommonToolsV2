import FWCore.ParameterSet.Config as cms

process = cms.Process("PICK_EVENTS")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring( '/store/data/Run2010A/EG/RECO/v4/000/142/557/B4AF9E2C-7EA3-DF11-9029-003048D3756A.root',
'/store/data/Run2010A/EG/RECO/v4/000/142/191/24F96F14-F29E-DF11-8BD3-003048F024C2.root',
'/store/data/Run2010A/EG/RECO/v4/000/142/954/34260DC1-F3A7-DF11-8A11-0030487CD7CA.root',
'/store/data/Run2010A/EG/RECO/v4/000/142/189/4E112A70-E59E-DF11-9027-001617E30D0A.root'
 ), 
    eventsToProcess = cms.untracked.VEventRange( '142557:80895186' , '142191:25487594' , '142954:34005975' , '142189:44075652' )
)

process.Out = cms.OutputModule("PoolOutputModule",
    outputCommands = cms.untracked.vstring('keep *'),
    fileName = cms.untracked.string('picked_events.root')
)


process.e = cms.EndPath(process.Out)


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)