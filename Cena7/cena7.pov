#include "shapes.inc"      // Inclusão de formas básicas do POV-Ray
#include "textures.inc"    // Inclusão de texturas básicas
#include "colors.inc"      // Inclusão das cores padrão
#include "woods.inc"       // Inclusão de texturas de madeira
#include "metals.inc"      // Inclusão de texturas metálicas
#include "../Base/base.inc"
#include "../Base/vaca.inc"
#include "../Base/vacaDourada.inc"


#macro fumacaImpacto(Pos)
union {
  #local i = 0;
  #while (i < 10)
    sphere {
      Pos + <rand(seed1)-0.5, rand(seed1)-0.5, rand(seed1)-0.5>*8, 1.5
      texture {
        pigment { color rgbt <0.3,0.3,0.3,0.7> } // Cinza meio transl�cido
        finish { ambient 1 diffuse 0 }    // Brilha por conta pr�pria
      }
    }
    #declare i = i + 1;
  #end
}
#end

#declare seed1 = seed(42); // Semente aleat�ria

// Declaração de variável para deslocamento que varia com o tempo (clock)
#declare deslocamento = -clock*40;

#if (clock >= 0.3)
  #declare lutaOscilacao = sin((clock - 0.3) * 4 * pi * 2) * 1.5;
#else
  #declare lutaOscilacao = 0;
#end

//POSI��O DA CAMERA
#declare posCamera1 = <-60, 70 -clock*10, 35>;
#declare posCamera2 = <-50, 7, 20>;
#declare posCamera3 = <-50, 7, 40>;   

#declare rotCamera1 = <-60, 10, 35>;
#declare rotCamera2 = <-60, 7, 30>;
#declare rotCamera3 = <-60, 7, 35> ;

#if (clock < 0.3)
  #declare posicaoCamera = posCamera1; 
  #declare rotacaoCamera = rotCamera1;
#else
    #if (clock < 0.8)
        #declare posicaoCamera = posCamera2;
        #declare rotacaoCamera = rotCamera2;
    #else
        #declare posicaoCamera = posCamera3;
        #declare rotacaoCamera = rotCamera3;        
    #end
#end
// Céu esférico com gradiente e efeito de nuvens turbulentas
sky_sphere {
  pigment {
    gradient z   // Gradiente na direção z (vertical)
    color_map {
      [0.5 color <0.85, 0.48, 0.48>] //  <1, 0.52, 0>
      [1.0 color <1, 0.52, 0>] //<0.85, 0.48, 0.48>               
    }
    scale 2   
  }
  pigment {
    bozo                // Efeito de nuvem tipo "bozo"
    turbulence 0.9      // Turbulência para nuvens realistas
    omega 0.7           // Frequência de turbulência
    color_map {
      [0.0 color rgb <0.85, 0.85, 0.85>]     // Cinza claro na base
      [0.1 color rgb <0.75, 0.75, 0.75>]     // Cinza um pouco mais escuro
      [0.5 color rgbt <1,1,1,1>]              // Branco translúcido no meio
      [1.0 color rgbt <1,1,1,1>]              // Branco translúcido no topo
    }
    scale <0.6, 0.3, 0.3>                     // Escala do efeito turbulento
  }
}


// Plano horizontal verde representando o chão
plane {
  y, 0             // Plano no eixo Y, na altura 0 (chão)
  pigment {color Green}  // Cor verde para o chão
}


// Fonte de luz principal, área de luz
light_source {
  <0, 15, -45>         // Posição da luz
  color White          // Cor da luz branca
  area_light <30, 0, 0>, <0, 0, 30>, 2, 2   // Luz de área para sombras suaves
  adaptive 1           // Ajuste adaptativo para qualidade
  jitter               // Aleatoriza a luz para suavizar sombras
}

// Segunda fonte de luz mais distante e intensa
light_source {
  <0, 300, -500>       // Luz distante para iluminação geral
  color White
}


// câmera posicionada do lado esquerdo
camera {
  location posicaoCamera   // <-50, 7, 20>
  look_at rotacaoCamera    // <-60, 7, 30> 
}

// ******  CENÁRIO  ******

// Instancia e posiciona a primeira árvore
object {
  arvore()
  scale <10, 10, 10>
  rotate <0, 20, 0>
  translate <-90, 6, 140>
}

// Instancia e posiciona a vaca
#if (clock < 0.3)
    object {
      vaca()
      scale <3, 3, 3>
      rotate <0, 180, 0>
      translate <-60, 6, 28>  
    }
#else
    #if (clock < 0.8)
        object {
          vaca_andando()
          scale <3, 3, 3>
          rotate <0, 180, 0>
          translate <-60, 6, 30 + lutaOscilacao>
          }
    #else
        object {
          vaca_golpe()
          scale <3, 3, 3>
          rotate <-100, -50, 90>
          translate <-60, 6, 30>
          }    
    #end  
#end  

// Vaca dourada
#if (clock < 0.3)
    object {
      vaca_dourada()
      scale <4, 4, 4>
      translate <-60, 8, 40>  
    }
#else
    #if (clock < 0.8)
        object {
          vaca_dourada_andando()
          scale <4, 4, 4>
          translate <-60, 8, 38 - lutaOscilacao>  
        }
    #else
        object {
          vaca_dourada_ferida()
          scale <4, 4, 4>
          translate <-60, 8, 38>  
        }    
    #end
#end
          
//Fuma�a
#if (clock >= 0.4 & clock < 0.8)
  object {
    fumacaImpacto(<-60, 7.5, 34>)
  }
#end