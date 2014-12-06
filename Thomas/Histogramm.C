
{
#include "TAxis.h"
#include "TH1.h"
#include "TArrayD.h"



	double m=0.1221422862;
	double t=-16.2882494;


	TH1I* Histogramm=&febex_energy_0_000_02;
TAxis *a=Histogramm->GetXaxis();
if(a->GetXbins()->GetSize())
{
TArrayD X(*(a->GetXbins()));
for(Int_t i = 0; i < X.GetSize(); i++) {X[i] = m*(X[i])+t;}
      a->Set((X.GetSize() - 1), X.GetArray()); // new Xbins

}
else{
      Histogramm->GetXaxis()->Set( a->GetNbins(),
              m*(a->GetXmin())+t, // new Xmin
              m*(a->GetXmax())+t );
}
Histogramm->GetXaxis()->SetTitle("Energie in keV");
Histogramm->GetYaxis()->SetTitle("Anzahl Events");
Histogramm->SetTitle("Messung 1");
Histogramm->SetStats(0);
Histogramm->Draw();
}