#include "../interface/GenJet.h"

void
panda::GenJet::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  pdgid = new UShort_t[nmax_];
}

void
panda::GenJet::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
}

void
panda::GenJet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pdgid", _branches);
}

void
panda::GenJet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
}

void
panda::GenJet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 's', pdgid, _branches);
}

void
panda::GenJet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
}

void
panda::GenJet::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}

panda::GenJet::GenJet(char const* _name/* = ""*/) :
  ParticleM(new GenJetArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0])
{
}

panda::GenJet::GenJet(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx])
{
}

panda::GenJet::GenJet(GenJet const& _src) :
  ParticleM(new GenJetArray(1, gStore.getName(&_src))),
  pdgid(gStore.getData(this).pdgid[0])
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;
}

panda::GenJet::GenJet(ArrayBase* _array) :
  ParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0])
{
}

panda::GenJet::~GenJet()
{
  destructor();
  gStore.free(this);
}

void
panda::GenJet::destructor()
{
  /* BEGIN CUSTOM GenJet.cc.destructor */
  /* END CUSTOM */

  ParticleM::destructor();
}

panda::GenJet&
panda::GenJet::operator=(GenJet const& _src)
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;

  return *this;
}

void
panda::GenJet::doSetStatus_(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::doSetStatus_(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pdgid", _branches);
}

void
panda::GenJet::doSetAddress_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::doSetAddress_(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", &pdgid, _branches, _setStatus);
}

void
panda::GenJet::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "", 's', &pdgid, _branches);
}

void
panda::GenJet::doReleaseTree_(TTree& _tree, TString const& _name)
{
  ParticleM::doReleaseTree_(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
}

void
panda::GenJet::doInit_()
{
  ParticleM::doInit_();

  pdgid = 0;
}

/* BEGIN CUSTOM GenJet.cc.global */
/* END CUSTOM */