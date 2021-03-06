#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class WinterAndReindeers{
public:
	string A,B,C;
	string Ar,Br;
	int dp[2503][2503];
	int dpr[2503][2503];
	vector<pii> lrA, lrB;
	
	int getNumber(vector <string> allA, vector <string> allB, vector <string> allC){
		FOR(i,allA.size()) A+=allA[i];
		FOR(i,allB.size()) B+=allB[i];
		FOR(i,allC.size()) C+=allC[i];
		Ar=A;Br=B;
		reverse(Ar.begin(),Ar.end());
		reverse(Br.begin(),Br.end());
		FOR(i,A.size()){
			FOR(j,B.size()){
				if(A[i]==B[j]){
					dp[i][j]=(i>0&&j>0?dp[i-1][j-1]:0)+1;
				}
				else {
					dp[i][j]=(i>0?dp[i-1][j]:0);
					dp[i][j]=max(dp[i][j],(j>0?dp[i][j-1]:0));
				}
				if(Ar[i]==Br[j]){
					dpr[i][j]=(i>0&&j>0?dpr[i-1][j-1]:0)+1;
				}
				else {
					dpr[i][j]=(i>0?dpr[i-1][j]:0);
					dpr[i][j]=max(dpr[i][j],(j>0?dpr[i][j-1]:0));
				}
			}
		}
		FOR(i,A.size()){
			if(A[i]!=C[0])continue;
			int posC=1;
			int j;
			for(j = i+1; j < A.size();j++){
				if(posC==C.size()) break;
				if(A[j]==C[posC]) posC++;
			}
			if(posC==C.size()) lrA.pb(mp(i,j-1));
		}
		FOR(i,B.size()){
			if(B[i]!=C[0])continue;
			int posC=1;
			int j;
			for(j = i+1; j < B.size();j++){
				if(posC==C.size()) break;
				if(B[j]==C[posC]) posC++;
			}
			if(posC==C.size()) lrB.pb(mp(i,j-1));
		}
		int ans = 0;
		if(lrA.size()==0||lrB.size()==0) return 0;
		for(auto a : lrA){
			for(auto b : lrB){
				int al=a.first; int ar=a.second;
				int bl=b.first; int br=b.second;
				ans = max(ans, (!al||!bl?0:dp[al-1][bl-1])+(ar==A.size()-1||br==B.size()-1?0:dpr[A.size()-ar-2][B.size()-br-2]));
			}
		}
		// for(auto a : lrA) printf("al:%d, ar:%d\n",a.first,a.second);
		// for(auto b : lrB) printf("bl:%d, br:%d\n",b.first,b.second);
		return ans+C.size();
	}
};
int main() {
	WinterAndReindeers obj;
	printf("%d",obj.getNumber(
{"SZPOKLWJDRLTBSCIEDPIWLAQIGESJSQHSJLRGLMWANRXRFNWAK", "ZTGJHXAUNFQJVXIOHNJQRJSHYMDOVWGEFHJESVHTIZIOJLJDPM", "OXBYUYOPQJKZTVJGKWXKEWPZHBJSUTHSYOEFJGWWYEOZLUHMGA", "BBSQRHCRTXMJVCAXXSUFAHYYAYZKHUHJRJSVOQHTYDWPBSZXSB", "ZIYRVGQMLUNWSCPIRZFCBTSEPLKGWFKHROUOYSRWMQOJAHYQMF", "EVSDCOMRYHGDMLXUKWYZCPRSKWGXULSUCKBSEPJEISZSGCEZWA", "PQRVLWIGROVJCDZXXPHQLSRZIHMGZRIOQRQETKZFBLDJIEMSFZ", "BHZFNWYWMXXGDPYLRAXGLMTBIYLBHCWHLSYOYHGMGOPPRZAXQM", "OMSYHGAGIUPJQBZXTHTOPOTMITNQWTOETONXWZGHUTIFKLGKLR", "NUWKMSYQCPUIVAHQATMSCKMAALKICSNXUCOVTYKRXAWZADJXWX", "QMNDHLDTTXSKNXTEZNJSQTFBCCFQMWHBVSSIIGVIJSUXIICAAH", "MKWYWTTJZPPKWLBMJAHTPUTIEBPBBMUEGYRHLTHXWGJPRWVHSH", "ZYAVQYECZTOZOABNANHRRBDDNDODXEUIOZIOIUOZXQTIHWAURO", "QRDQWCVLXZIPODIISPQNZOMCWVAPTGRGDFNYYTKWWQQTMIUUYV", "GAIHFSHCCXHUUYYHTGDGLFCIEBDUTOEUNFHDAXPHBSYWZTPWJN", "GJNCPXRJVBVCCEFKBEMGSDYMZMMKWDEHFKRUQBYVECMPESROMD", "XLLUBRYYESHQLZMREWQNKQITXGIIGQUSKWTCZNLTERXBLTZYDY", "ZVAHNKIXJWZZTDJPQSUOWKVFCCOCKVRJBFRJPCGDJDRWDNPOSR", "JGDRQRVQTVPPAZHLTJQVCCLPEZTSJPYNZFROTQPOXMWHHWEWNV", "CBVDKUZIFIFRTWQQEOJUEQBNSKWZEEWZKAOJURSQGSCZVHHUJZ", "UMIGOFHWBKKFLUWZKCTKAGXKSMFAUWINSJLSOJTRXHWMHLVBYP", "ECJEIWWSTNEUIQUBPGUGWGNMIKDWICKDILSNPDQSVMTERDFBLH", "WBAFBGARCSFIJYLBIIMOFGXEIRPBTYWQZAPKKCAFCOMVNTMDHZ", "XLEFPPYEBEOEQZNBHYCWMFYAQQIANNYHQOUIZVEAVGZJWOBLSG", "WNKVJLNIVQCWVZXTCTHYNMUXQKWWMTFISGGLGCOXPIPYTDBAMR", "YKBOKMWGSDDPQKRZYJCHZTMIEPAGWHROQKHWUDBCIHPQWAQZXU", "GKVAKVLAVKSWFZSDBVQIDHTBCDEYTMPPHKUHSXORPUFWHJRUTK", "SSLHLRXLYDXVKOSAGGMPBG"}, {"ZVBAFAZJOHQSSWTORCKQAXSREHNRLYJIWTMHGLKOZFKMMXTYVO", "XHFKXOPVYBJZOXHZUBDNTOAMZOTTCJTUEGMPQKCDBBGCKJQTEB", "ICHZNPPRQISWBDHOYNCSAETLGBFVIOCFWXWDRNLFFBFHVYXZUK", "JWOCYHZQJZDHTBRRRLLKTCHFNCTPIRNAWONYDWWVUABUQCIMCN", "LHQODEMAKMUNMAXIOMKEYWCOFQBKDMZOIZGQIPZAYIXRYDWSOV", "HZTKGZSKWPTKQCEXRNNXSKYWNDQIZLZKLNISSAMQAZHLNDNVIL", "TKOIAFMEICGGUZXHRDJZZHERUSWAVNVSLONOASRUDRNLDKLDKF", "ZTAGIENATJZWXCLKKULNCAQPTONEQLNBTODDBMIVAZXZMCOJDH", "ISWKAXIAGTUTAFRSVPPHURAAAIXZTWDYRUUMQADJEPVVCVOIDW", "MTPBNMQUIOPIWPUWCZDAPDZGHAVVIYIROJNOLSOWRMVVJIQSWR", "ICMZSXAVDQAMNFHWFGEOHSKKEFUTXXIBHPULNLWXQWWZDGDJGE", "QWAPBHLPUDOEMNNTPOUAHGXJHZJBEPLTTRIABWUCRJMBVBOZVM", "XOBATKHQSQCHLHTBOFUIKWAFKCOWUUNTFHPKDEYHOKQUWQVWTT", "HHHUGJZMFEUINIPBNCIZOCKAADALLJREQTKHUDBLPRZLSRWXOC", "CSLUTWQZSQTIJVCWNPFLRLUKDIAOHQJHRAGLGRIYKLDKDFRDRX", "JSTCWRSXGYWFNHCBKPMESUPMTRVIPFBKTBWZFAHOEVNHXBRHHF", "OBGYWCVHKTDOXQTEKIWWURZBLMLDLFIBDVEMUNNLXUBYKVVRGK", "TRERPTISIZXHREVNXQUEZXKUGROOHRHUDIDGVHTJHYEZKYHPFX", "WGPRPSEACCXKWVIXVFHQFAWKFDJPYEEVDGGATFIEKIXEYRFCPX", "SCJKCFGQMYHJMJTIMDSPIZHWZIZCYUCEGLMMBGYGFVTQVZQATX", "LGIBYZZKIAJXMBHMKQLWHQNGHLVLZGPPXOOEOQXPPBPMBLXNKE", "OFMNIUMJCAFCUYVDCUETERQPJJWAKNKXTLZQFLJNWKXGKFYLNU", "KBIYSPLKHJUCFUWOHZVPHJBJYOVDLNBFRKVBEMWYTFJYNQMGZA", "GBKWEKKOUXDCYNKHTOSFYTLUCENTOILFULDVRXLONVKXZECXEP", "KMZZGXLUAHMJYECSLDJESDCPJIKVPAUDVKXGLLISAAMBOVJKDQ", "RKDORJFNYGHHHPTZIFAWFTZQGEMNH"}, {"PQYICTM"}
		));
	return 0;
}