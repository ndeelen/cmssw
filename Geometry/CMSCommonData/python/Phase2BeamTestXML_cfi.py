import FWCore.ParameterSet.Config as cms

# This config was generated automatically using generate2023Geometry.py
# If you notice a mistake, please update the generating script, not just this config

XMLIdealGeometryESSource = cms.ESSource("XMLIdealGeometryESSource",
    geomXMLFiles = cms.vstring(
         # World volume creation and default CMS materials
        'Geometry/CMSCommonData/data/materials.xml',
        'Geometry/CMSCommonData/data/rotations.xml',
        'Geometry/CMSCommonData/data/extend/cmsextent.xml',
        'Geometry/CMSCommonData/data/cms.xml',
        'Geometry/CMSCommonData/data/cmsMother.xml',
        
         # Define standalone Phase 1 BPIX module and associated materials
        'Geometry/TrackerCommonData/data/PhaseI/pixbarmaterial.xml',
        'Geometry/TrackerCommonData/data/Run2/trackermaterial.xml',   #sometimes included via Run2, sometimes via PhaseI, which one to choose?
        'Geometry/TrackerCommonData/data/PhaseI/pixfwdMaterials.xml',
        'Geometry/CMSCommonData/data/Phase1BPIXLayer4Module.xml',
        
         # Define DUT and telescope
        'Geometry/CMSCommonData/data/DUT.xml',
        'Geometry/CMSCommonData/data/telescope.xml',
        
         # Configurable parameters
        'Geometry/CMSCommonData/data/Phase2BeamTestConstants.xml'
      
    ),
    rootNodeName = cms.string('cms:OCMS')
)
