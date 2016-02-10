#ifndef TkDetLayers_Phase2OTtiltedBarrelLayer_h
#define TkDetLayers_Phase2OTtiltedBarrelLayer_h


#include "TrackingTools/DetLayers/interface/RodBarrelLayer.h"
#include "Phase2OTBarrelLayer.h"
#include "Phase2OTBarrelRod.h"
#include "Phase2OTEndcapRing.h"
#include "Utilities/BinningTools/interface/PeriodicBinFinderInPhi.h"
#include "SubLayerCrossings.h"



/** A concrete implementation for Phase2OTBarrel layer 
 *  built out of BarrelPhase2OTBarrelRod
 */

#pragma GCC visibility push(hidden)
class Phase2OTtiltedBarrelLayer GCC11_FINAL : public Phase2OTBarrelLayer {
 public:
  typedef PeriodicBinFinderInPhi<double>   BinFinderType;

  Phase2OTtiltedBarrelLayer(std::vector<const Phase2OTBarrelRod*>& innerRods,
                            std::vector<const Phase2OTBarrelRod*>& outerRods,
                            std::vector<const Phase2OTEndcapRing*>& negRings, 
                            std::vector<const Phase2OTEndcapRing*>& posRings);
  
  ~Phase2OTtiltedBarrelLayer();
  
  virtual const std::vector<const GeomDet*>& basicComponents() const {return theBasicComps;}
  //virtual const std::vector<const GeometricSearchDet*>& components() const {return theComps;}
  
  void groupedCompatibleDetsV( const TrajectoryStateOnSurface& tsos,
			       const Propagator& prop,
			       const MeasurementEstimator& est,
			       std::vector<DetGroup> & result) const;
    

  virtual SubDetector subDetector() const { return GeomDetEnumerators::subDetGeom[GeomDetEnumerators::P2OTB];}

 private:
  Phase2OTBarrelLayer* thePhase2OTBarrelLayer;
  //std::vector<const GeometricSearchDet*> theComps;
  std::vector<const GeometricSearchDet*> theNegativeRingsComps;
  std::vector<const GeometricSearchDet*> thePositiveRingsComps;
  std::vector<const GeomDet*> theBasicComps;

  ReferenceCountingPointer<BoundCylinder>  theCylinder;
  
};


#pragma GCC visibility pop
#endif 
