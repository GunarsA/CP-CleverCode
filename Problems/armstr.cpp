#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<string> armstr;
	armstr.push_back("0");armstr.push_back("1");armstr.push_back("2");armstr.push_back("3");armstr.push_back("4");armstr.push_back("5");armstr.push_back("6");armstr.push_back("7");armstr.push_back("8");armstr.push_back("9");
	armstr.push_back("153");armstr.push_back("370");armstr.push_back("371");armstr.push_back("407");
	armstr.push_back("1634");armstr.push_back("8208");armstr.push_back("9474");
	armstr.push_back("54748");armstr.push_back("92727");armstr.push_back("93084");
	armstr.push_back("548834");
	armstr.push_back("1741725");armstr.push_back("4210818");armstr.push_back("9800817");armstr.push_back("9926315");
	armstr.push_back("24678050");armstr.push_back("24678051");armstr.push_back("88593477");
	armstr.push_back("146511208");armstr.push_back("472335975");armstr.push_back("534494836");
	armstr.push_back("4679307774");
	armstr.push_back("32164049650");armstr.push_back("32164049651");armstr.push_back("40028394225");armstr.push_back("42678290603");armstr.push_back("44708635679");armstr.push_back("49388550606");armstr.push_back("82693916578");armstr.push_back("94204591914");
	armstr.push_back("28116440335967");
	armstr.push_back("4338281769391370");armstr.push_back("4338281769391371");
	armstr.push_back("21897142587612075");armstr.push_back("35641594208964132");armstr.push_back("35875699062250035");
	armstr.push_back("1517841543307505039");armstr.push_back("3289582984443187032");armstr.push_back("4498128791164624869");armstr.push_back("4929273885928088826");
	armstr.push_back("63105425988599693916");
	armstr.push_back("128468643043731391252");armstr.push_back("449177399146038697307");
	armstr.push_back("21887696841122916288858");armstr.push_back("27879694893054074471405");armstr.push_back("27907865009977052567814");armstr.push_back("28361281321319229463398");armstr.push_back("35452590104031691935943");
	armstr.push_back("174088005938065293023722");armstr.push_back("188451485447897896036875");armstr.push_back("239313664430041569350093");
	armstr.push_back("1550475334214501539088894");armstr.push_back("1553242162893771850669378");armstr.push_back("3706907995955475988644380");armstr.push_back("3706907995955475988644381");
	armstr.push_back("121204998563613372405438066");armstr.push_back("121270696006801314328439376");armstr.push_back("128851796696487777842012787");armstr.push_back("174650464499531377631639254");armstr.push_back("177265453171792792366489765");
	armstr.push_back("14607640612971980372614873089");armstr.push_back("19008174136254279995012734740");armstr.push_back("19008174136254279995012734741");armstr.push_back("23866716435523975980390369295");
	armstr.push_back("1145037275765491025924292050346");armstr.push_back("1927890457142960697580636236639");armstr.push_back("2309092682616190307509695338915");
	armstr.push_back("17333509997782249308725103962772");
	armstr.push_back("186709961001538790100634132976990");armstr.push_back("186709961001538790100634132976991");
	armstr.push_back("1122763285329372541592822900204593");
	armstr.push_back("12639369517103790328947807201478392");armstr.push_back("12679937780272278566303885594196922");
	armstr.push_back("1219167219625434121569735803609966019");
	armstr.push_back("12815792078366059955099770545296129367");
	armstr.push_back("115132219018763992565095597973971522400");armstr.push_back("115132219018763992565095597973971522401");

	string x;
	bool ir=false;
	cin>>x;
	for(unsigned short int i=0;i<armstr.size();i++){
		if(x==armstr[i]){cout<<"IR"<<endl;ir=true;break;}
	}
	if(!ir){cout<<"NAV"<<endl;}
    return 0;
}
