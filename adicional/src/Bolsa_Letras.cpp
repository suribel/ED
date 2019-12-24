
    Bolsa_Letras()
    {

    }
    int size() const
    {
        return bolsa.size();
    }

    void llenar(const Conjunto_Letras &CL)
    {
        set<Letra>::iterator it;

        for (it=CL.begin(); it!=CL.end(); ++it){        
            for (int i = 0; i < (*it).getApariciones(); ++i)
            {
                bolsa.insert((*it).getCaracter());
            }
            
        }
    }

    vector<char> sacar(int num_letras)
    {
        multiset<char>::iterator it;
        vector<char> sacados;        

        for (int i = 0; i < num_letras; ++i)
        {            
            srand(time(NULL));
            int rand = rand() % bosa.size();
            it = bolsa.begin() + rand;
            sacados.insert(*it);
            bolsa.erase (it);
        }

        return sacados;        
    }

    ostream & operator<<(ostream & os, const Bolsa_Letras &BL)
    {
        set<char>::iterator it;

        for (it=BL.begin(); it!=BL.end(); ++it){        
            os << (*it) << endl;
        }

        return os;
    }

    Conjunto_Letras & operator>>(const Conjunto_Letras &CL, Bolsa_Letras &BL)
    {
        BL.llenar(CL);
    }