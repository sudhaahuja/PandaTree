#ifndef PandaTree_Objects_ParticleP_h
#define PandaTree_Objects_ParticleP_h
#include "Constants.h"
#include "Particle.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class ParticleP : public Particle {
  public:
    struct datastore : public Particle::datastore {
      datastore() : Particle::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<ParticleP> array_type;
    typedef Collection<ParticleP> collection_type;

    typedef Particle base_type;

    ParticleP(char const* name = "");
    ParticleP(ParticleP const&);
    ParticleP(datastore&, UInt_t idx);
    ~ParticleP();
    ParticleP& operator=(ParticleP const&);

    double pt() const { return pt_; }
    double eta() const { return eta_; }
    double phi() const { return phi_; }
    double m() const { return 0.; }
    void setPtEtaPhiM(double pt, double eta, double phi, double);
    void setXYZE(double px, double py, double pz, double);

  protected:
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;

  public:
    /* BEGIN CUSTOM ParticleP.h.classdef */
    /* END CUSTOM */

    void destructor() override;

  protected:
    ParticleP(ArrayBase*);

    void doSetStatus_(TTree&, TString const&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&, TString const&) const override;
    void doSetAddress_(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&, TString const&) override;
    void doInit_() override;
  };

  typedef ParticleP::array_type ParticlePArray;
  typedef ParticleP::collection_type ParticlePCollection;
  typedef Ref<ParticleP> ParticlePRef;
  typedef RefVector<ParticleP> ParticlePRefVector;

  /* BEGIN CUSTOM ParticleP.h.global */
  /* END CUSTOM */

}

#endif
