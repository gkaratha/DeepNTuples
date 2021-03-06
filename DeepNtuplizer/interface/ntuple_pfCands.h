/*
 * ntuple_pfcands.h
 *
 *  Created on: 13 Feb 2017
 *      Author: jkiesele
 */

#ifndef DEEPNTUPLES_DEEPNTUPLIZER_INTERFACE_NTUPLE_PFCANDS_H_
#define DEEPNTUPLES_DEEPNTUPLIZER_INTERFACE_NTUPLE_PFCANDS_H_

#include "ntuple_content.h"

class ntuple_pfCands: public ntuple_content{
public:

	ntuple_pfCands():ntuple_content(){}

	void getInput(const edm::ParameterSet& iConfig);
	void initBranches(TTree* );
	void readEvent(const edm::Event& iEvent);



	//use either of these functions

	bool fillBranches(const pat::Jet &, const size_t& jetidx, const  edm::View<pat::Jet> * coll=0);

private:
	unsigned int n_Cpfcand_;
	float nCpfcand_;

	static constexpr size_t max_pfcand_=100;

	float  Cpfcan_pt_[max_pfcand_];
	float  Cpfcan_phirel_[max_pfcand_];
	float  Cpfcan_etarel_[max_pfcand_];
	float  Cpfcan_puppiw_[max_pfcand_];
	float   Cpfcan_VTX_ass_[max_pfcand_];

	// covariance
	float  Cpfcan_dz_[max_pfcand_];
	float  Cpfcan_dxy_[max_pfcand_];

	float  Cpfcan_dxyerr_[max_pfcand_];
	float  Cpfcan_dxysig_[max_pfcand_];

	float  Cpfcan_dptdpt_[max_pfcand_];
	float  Cpfcan_detadeta_[max_pfcand_];
	float  Cpfcan_dphidphi_[max_pfcand_];
	float  Cpfcan_dxydxy_[max_pfcand_];
	float  Cpfcan_dzdz_[max_pfcand_];
	float  Cpfcan_dxydz_[max_pfcand_];
	float  Cpfcan_dphidxy_[max_pfcand_];
	float  Cpfcan_dlambdadz_[max_pfcand_];

	// ID, skipped "charged hadron" as that is true if now the other
	// TODO (comment of Markus Stoye) add reco information
	float Cpfcan_isMu_[max_pfcand_]; // pitty that the quality is missing
	float Cpfcan_isEl_[max_pfcand_]; // pitty that the quality is missing
	float Cpfcan_charge_[max_pfcand_];

	// track quality
	float Cpfcan_lostInnerHits_[max_pfcand_];
	float Cpfcan_chi2_[max_pfcand_];
	float Cpfcan_quality_[max_pfcand_];

	//Neutral Pf candidates
	unsigned int n_Npfcand_;
	float nNpfcand_;
	float  Npfcan_pt_[max_pfcand_];
	float  Npfcan_phirel_[max_pfcand_];
	float  Npfcan_etarel_[max_pfcand_];
	float  Npfcan_isGamma_[max_pfcand_];
	float  Npfcan_HadFrac_[max_pfcand_];



};


#endif /* DEEPNTUPLES_DEEPNTUPLIZER_INTERFACE_NTUPLE_PFCANDS_H_ */
