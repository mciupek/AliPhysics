///////////////////////////////////////////////////////////////////////////
//                                                                       //
// AliFemtoESDTrackCut: A basic track cut that used information from     //
// ALICE ESD to accept or reject the track.                              //  
// Enables the selection on charge, transverse momentum, rapidity,       //
// pid probabilities, number of ITS and TPC clusters                     //
// Author: Marek Chojnacki (WUT), mchojnacki@knf.pw.edu.pl               //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#ifndef ALIFEMTOXITRACKCUT_H
#define ALIFEMTOXITRACKCUT_H

#include "AliFemtoV0TrackCut.h"

class AliFemtoXiTrackCut : public AliFemtoV0TrackCut 
{
  public:
  enum XiType {kXiMinus = 0, kXiPlus=1, kAll = 99, kXiMinusMC = 101, kXiPlusMC=102};
  typedef enum XiType AliFemtoXiType;


  AliFemtoXiTrackCut();
  virtual ~AliFemtoXiTrackCut();

  virtual bool Pass(const AliFemtoXi* aXi);

  virtual AliFemtoString Report();
  virtual TList *ListSettings();
  virtual AliFemtoParticleType Type(){return hbtXi;}

  bool IsPionNSigmaBac(float mom, float nsigmaTPCPi, float nsigmaTOFPi);

  void SetEtaXi(double x);
  void SetPtXi(double min, double max);
  void SetChargeXi(int x);
  void SetEtaBac(double x);
  void SetPtBac(double min, double max);
  void SetTPCnclsBac(int x);
  void SetNdofDaughters(double x);
  void SetStatusDaughters(unsigned long x);
  void SetInvariantMassXi(double min, double max);
  void SetMaxDcaXi(double x);
  void SetMaxDcaXiBac(double x);
  void SetMinDcaXiDaughters(double x);
  void SetMaxCosPointingAngleXi(double max);
  void SetParticleTypeXi(short x);
 
  
 private:   // here are the quantities I want to cut on...

  double fMaxEtaXi;
  double fMinPtXi;
  double fMaxPtXi;
  int fChargeXi;
  
  double fMaxEtaBac;
  double fMinPtBac;
  double fMaxPtBac;
  int fTPCNclsBac;
  double fNdofBac;
  unsigned long fStatusBac;
  double fMaxDcaXi;
  double fMaxDcaXiBac;
  double fMinDcaXiDaughters;
  double fMaxCosPointingAngleXi;
  double fMaxDecayLengthXi;
  double fInvMassXiMin;
  double fInvMassXiMax;
  short  fParticleTypeXi;
  

#ifdef __ROOT__ 
  ClassDef(AliFemtoXiTrackCut, 1)
#endif

};


#endif

