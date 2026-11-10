#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Vapor
{
	private:
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	string  numeCapitan;
	int nrBilete;
	//constr fara parametri
	public:
	Vapor(){
	this->capacitate=0;
	this->nrPersoaneImbarcate=0;
	this->varstePasageri=NULL;
	this->numeCapitan="NA";
	this->nrBilete=0;

	}
	//constr cu param -validari
	Vapor(int capacitateInit,int nrPersoaneImbarcateInit,int* varstePasageriInit,string numeCapitanInit,int nrBileteInit)
	{
		if (capacitateInit > 0)
		{
			this->capacitate=capacitateInit;

	}
		else {
			this->capacitate=0;
		}
		if (nrPersoaneImbarcateInit > 0  && nrPersoaneImbarcateInit <= this->capacitate && varstePasageriInit != nullptr)
		{
		this->nrPersoaneImbarcate=nrPersoaneImbarcateInit;
			this->varstePasageri=new int[nrPersoaneImbarcateInit];
			for (int i = 0;i < nrPersoaneImbarcateInit;i++)
			{
			this->varstePasageri[i]=varstePasageriInit[i];
			}
		}
		else {
			this->nrPersoaneImbarcate=0;
			this->capacitate=NULL;
		}
		if (numeCapitanInit.length() > 0)
		{
			this->numeCapitan=numeCapitanInit;
		}
		else {
			this->numeCapitan="NA";
		}
		if (nrBileteInit > 0)
		{
			this->nrBilete=nrBileteInit;
		}
		else {
			this->nrBilete=0;
		}
		
	}
	//destructor
	~Vapor()
	{
		if (varstePasageri!= nullptr)
		{
			delete[]this->varstePasageri;
	}
	}
	//constructorul de coiere
	Vapor(const Vapor& v) {

		if (v.nrPersoaneImbarcate > 0  && v.varstePasageri != nullptr)
		{
			this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			this->varstePasageri = new int[v.nrPersoaneImbarcate];
			for (int i = 0;i < v.nrPersoaneImbarcate;i++)
			{
				this->varstePasageri[i] = v.varstePasageri[i];
			}
		
		}
		else {
			this->nrPersoaneImbarcate = 0;
			this->varstePasageri = nullptr;
		}
		this->capacitate=v.capacitate;
		this->nrBilete=v.nrBilete;
		this->numeCapitan=v.numeCapitan;
	}
	//getter si setter pt nrBilete si numeCapitan
	string getNumeCapitan()
	{
		return this->numeCapitan;
	}
	void setNumeCapitan(string numeCapitanNou)
	{
		if(numeCapitanNou.length()>0)
		{
			this->numeCapitan=numeCapitanNou;
	}
	}
	int getNrBilete() {
		return this->nrBilete;
	}
	void setNrBilete(int nrBileteNoi)
	{
		if (nrBilete > 0)
		{
			this->nrBilete=nrBileteNoi;
	}
		}

		//op =
	Vapor operator=(const Vapor& v)
	{
		if (this == &v) {
		return *this;
	}

		if (varstePasageri != nullptr)
		{
			delete[]this->varstePasageri;
		}

		if (v.nrPersoaneImbarcate > 0 && v.nrPersoaneImbarcate <= this->capacitate && v.varstePasageri != nullptr)
		{
			this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			this->varstePasageri = new int[v.nrPersoaneImbarcate];
			for (int i = 0;i < v.nrPersoaneImbarcate;i++)
			{
				this->varstePasageri[i] = v.varstePasageri[i];
			}
		}
		this->capacitate = v.capacitate;
		this->nrBilete = v.nrBilete;
		this->numeCapitan = v.numeCapitan;
		return *this;
	}

	//op<<
	friend ostream& operator<<(ostream& out, const Vapor& v)
	{
		out<<v.nrBilete<<", "<<v.numeCapitan<<", "<<v.nrPersoaneImbarcate<<", "<<v.capacitate<<", ";
		for (int i = 0;i < v.nrPersoaneImbarcate;i++)
		{
			out<<v.varstePasageri[i]<<", ";
		}
		out<<endl;
		return out;

		

	}
	//op>>
	friend istream& operator>>(istream& in, Vapor& v)
	{
		//pt numeCapitan
		cout<<"Nume:";
		string nume;
		in>>nume;
		if (nume.length() > 0)
		{
			v.numeCapitan=nume;
		}
		return in;
	}
	//++
	//preincrementare ++v
	Vapor& operator++()
	{
		this->nrPersoaneImbarcate++;
		return *this;
	}
	//postincrementare v++
	Vapor& operator++(int) {
	Vapor copie=*this;
	this->nrPersoaneImbarcate++;
	return copie;

	}
		//op functie cate persoane mai pot fi imbarcate 
	int operator()()
	{
		return this->capacitate-this->nrPersoaneImbarcate;
		}
		

		//op > capacitatea
	bool operator>(const Vapor& v)const
	{
		if (this->capacitate > v.capacitate)
		{
			return true;
		}
		else
		{
			return false;
		}

		
		}
		//cast la int  minor=varsta sub 18 ani

	explicit operator int()
	{
	int minori=0;
	for (int i = 0;i < this->nrPersoaneImbarcate;i++)
	{
		if (this->varstePasageri[i] < 18)
		{
			minori++;
		}
		return minori;
	}
		}
		//calculare varstemedie()
	float calculeazaVarstaMedie()
	{
		if (this->nrPersoaneImbarcate == 0)
		{
			return 0;
		}
		float suma =0;
		for (int i = 0;i < this->nrPersoaneImbarcate;i++)
		{
			suma+=this->varstePasageri[i];
		}
		return suma/this->nrPersoaneImbarcate;
		}
};
int main()
{
//constr fara param
	Vapor v1;
	cout<<v1<<endl;

	//constr cu param 
	int t[]={34,12,35,23};
	Vapor v2(6,4,t,"Matei",4);
	cout<<v2<<endl;

	//const de copiere 
	Vapor v3=v2;
	cout<<v3<<endl;

	//op=
	v1=v2;
	cout<<v2<<endl;

	//getter si setter
	cout<<v1.getNrBilete()<<endl;
	v1.setNrBilete(6);
	cout<<v1.getNrBilete()<<endl;
	cout<<v1.getNumeCapitan()<<endl;
	v1.setNumeCapitan("Marius");
	cout<<v1.getNumeCapitan()<<endl;
	//>>
	Vapor v4;
	cin>>v4;
	cout<<v4<<endl;

	//++
	Vapor v5(6, 4, t, "Matei", 4);
	cout<<(++v5).getNrBilete()<<endl;
	cout<<(v5++).getNrBilete()<<endl;
	cout<<v5.getNrBilete()<<endl;

	//op ()
	cout<<v2()<<endl;
	cout<<v1()<<endl;

	//>
	Vapor v8(6, 4, t, "Matei", 4);
	cout<<(v8>v5)<<endl;

	//cast 
	cout<<(int)v2<<endl;

	//clacularea varsta medie;
	cout<<v2.calculeazaVarstaMedie()<<endl;
}

//de facut cast [] +

