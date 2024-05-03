from threading import active_count


class Trajet:
    def __init__(self,depart=None,arriver=None,cout=None,temps=None):
        self.depart=depart
        self.arriver=arriver
        self.cout=cout
        self.temps=temps
        
class Node:
    def __init__(self,trajet=None):
        self.data=trajet
        self.next=None
class pile:
    def __init__(self): 
        self.head=None
    def empiler(self,t):
        new=Node(t)
        new.next=self.head
        self.head=new
    def depiler(self):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            actuel=self.head
            self.head=actuel.next
        
    def afficher(self):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            actuel=self.head
            while(actuel is not None):
                print("le depart est:",actuel.data.depart)
                print("l'arriver est",actuel.data.arriver)
                print("le tarif est",actuel.data.cout)
                print("le temps mis  est",actuel.data.temps)
                print("                                ")
                actuel=actuel.next
    def rechecher(self,depart,arriver):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            actuel=self.head
            i=0
            while(actuel is not None):
                if((actuel.data.depart==depart)and(actuel.data.arriver==arriver)):
                    print("trajet trouver:   depart:",actuel.data.depart,"arriver:",actuel.data.arriver,"cout:",actuel.data.cout,"tarif",actuel.data.temps)
                    i=i+1
                actuel=actuel.next
            if(i>0):
                print("vous avez deja realiser ce trajet ",i,"fois")

    def nombre(self):
        actuel1=self.head
        i=0
        while(actuel1 is not None):
            i+=1
            actuel1=actuel1.next  
        return i  
    def minim(self):
        f=Trajet()
        actuel=self.head
        mini=actuel.data
        while(actuel is not None):
            if(actuel.data.cout<mini.cout):
               mini=actuel.data
            actuel=actuel.next
        return mini
    def suprimer(self,l):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            i=0
            actuel=self.head
            actuel1=self.head
            while((actuel.next)and(actuel.data.cout != l) ):
                i=i+1
                actuel1=actuel
                actuel=actuel.next
            if((actuel.data.cout==l)and(i>0)):  
                actuel1.next=actuel.next
            elif((actuel.data.cout==l)and (i==0)):
                self.head=actuel.next
        

    def trie(self):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            pi=pile()
            while(p.head is not None):
              c=p.minim()
              p.suprimer(c.cout)
              pi.empiler(c)
            p.head=pi.head
        
    def minimt(self):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            f=Trajet()
            actuel=self.head
            mini=actuel.data
            while(actuel is not None):
                if(actuel.data.temps<mini.temps):
                   mini=actuel.data
                actuel=actuel.next
            return mini
    
    def suprimert(self,l):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            i=0
            actuel=self.head
            actuel1=self.head
            while((actuel.next)and(actuel.data.temps != l) ):
                i=i+1
                actuel1=actuel
                actuel=actuel.next
            if((actuel.data.temps==l)and(i>0)):  
                actuel1.next=actuel.next
            elif((actuel.data.temps==l)and (i==0)):
                self.head=actuel.next
                
    def triet(self):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            pi=pile()
            k=p.nombre()
            while(p.head is not None):
              c=p.minimt()
              p.suprimert(c.temps)
              pi.empiler(c)
            p.head=pi.head        

    def temptotal(self):
        actuel=p.head
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            c=0
            while(actuel is not None):
                c+=actuel.data.temps
                actuel=actuel.next
                k=0
            k=c%60
            s=0
            s=(c-k)/60
            print("le temps total est",s,"Heure et",k,"minutes")

        
    def couttotal(self):
        if(self.head==None):
            print("desole la pile es vide")
        else:    
            actuel=p.head
            c=0
            while(actuel is not None):
                c+=actuel.data.cout
                actuel=actuel.next
            return c;
    
    def save(self,departs=None,arrivers=None,temps=0,couts=0):
       e=Trajet(departs,arrivers,temps,couts)
       p.empiler(e)
       
      






p=pile()
p.save("ekounou","chateau",400,1500)
p.save("amadou","chateau",2,1)
p.save("chateau","chateau",456,15)
p.save("bouda","chateau",1000,30)
p.save("idem","chateau",10,98)
p.save("idem","chateau",10,98)


choix=1
while(choix !=0 ):
    print("**************************************************************************")
    print("*****BIENVENUE DANS CE PROGRAMME DE MANIPULATION DES TRAJETS PARCOURUES****")
    print("**************************************************************************")
    print("                                ")
    print("VOICI LES FONCTIONS DISPONIBLES:")
    print("                                ")
    print("1:EMPILER UN TRAJETS PARCOURUES")
    print("                                ")
    print("2:DEPILER UN TRAJETS PARCOURUES")
    print("                                ")
    print("3:AFFICHER LA PILE TRAJETS PARCOURUES ")
    print("                                ")
    print("4:RECHERCHER UN TRAJET PARCOURUE DANS LA PILE")
    print("                                ")
    print("5:TRIER LA PILE TRAJETS PARCOURUES EN FONCTION DU TARIF")
    print("                                ")
    print("6:TRIER LA PILE TRAJETS PARCOURUES EN FONCTION DU TEMPS MIS")
    print("                                ")
    print("7:LE TEMPS MIS TOTAL POUR TOUS LES TRAJETS")
    print("                                ")
    print("8:LA SOMME TOTAL DEPENSER POUR TOUS LES TRAJETS")
    print("                                ")
    print("                                ")
    print("taper sur la touche **0**poursortir du code ")
    print("                                ")
    choix= int(input("votrer choix:"))
    if(choix==1):
        i=0
        print("entrer le nombre de trajet a ajouter")
        n=int(input("le nombre trajet:"))
        while i != n:
            na=input("entrer le depart du trajeta ajouter:");
            print("                 ")
            ha=input("entrer l'arriverdu trajeta ajouter:")
            print("                 ")
            aa=int(input("entrer le temps mis sur le du trajet a ajouter:"))
            print("                 ")
            da=int(input("entrer le cout du trajet  a ajouter:"))
            p.save(na,ha,aa,da)
            i=i+1
    elif(choix==2):
        print("                 ")
        p.depiler()
        print("                 ")
    elif(choix==3):
        print("                 ")
        p.afficher()
        print("                 ")
    elif(choix==4):
        g=input("entrer le depart du trajet rechercher :")
        h=input("entrer l'arriver du trajet rechercher :")
        p.rechecher(g,h)
        print("                 ")
        print("                 ")
    elif(choix==5):
        print("la pile trie est")
        p.trie()
        print("                 ")
        p.afficher()
        print("                 ")
    elif(choix==6):
        print("la pile trie en fonction du temps est")
        p.triet()
        print("                 ")
        p.afficher()
        print("                 ")
    elif(choix==7):
        print("                 ")
        p.temptotal()
        print("                 ")
    elif(choix==8):
        print("                 ")
        c=0
        c=p.couttotal()
        print("le cout total  est:",c,"fcfa")
        print("                 ")
    else:
        print("!!!!!!""error""veillez choisir l'une des proposition precedentes!!!!!")
     



