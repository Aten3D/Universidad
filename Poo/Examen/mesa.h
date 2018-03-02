#ifndef mesa_h
#define mesa_h
class mesa:public mueble{
	private:
		int patas_;
		string material;
	public:
		mesa(
			int id,
			string nombre= "NO_ASIGNADO",
			string modelo= "NO_ASIGNADO",
			string fecha= "NO_ASIGNADO",
			string color ="NO_ASINGADO",
			int patas=0,
			string material="NO_ASIGNADO");
		int getpatas(){return patas_;};
		string getmaterial(){return material_;};
		void setPatas();
		void setMaterial();
		bool checkEstado();
}
#endif