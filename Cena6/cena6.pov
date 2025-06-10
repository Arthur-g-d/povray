#include "shapes.inc"      // Inclusão de formas básicas do POV-Ray
#include "textures.inc"    // Inclusão de texturas básicas
#include "colors.inc"      // Inclusão das cores padrão
#include "woods.inc"       // Inclusão de texturas de madeira
#include "metals.inc"      // Inclusão de texturas metálicas
#include "../Base/base.inc"
#include "../Base/vaca.inc"
#include "../Base/vacaVelha.inc"

// Declaração de variável para deslocamento que varia com o tempo (clock)
#declare deslocamento = -clock*10;

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
  rotate<30,-30,0>
}


cylinder {
  <-80, -10, 30>, <-80, 0, 30>, 20 // Base em (0,0,0), topo em y=5, raio = 20
  texture {
    pigment { color Green } // Verde grama
    finish { phong 0.2 }
  }
}


// Segunda fonte de luz mais distante e intensa
light_source {
  <200, 300, 500>       // Luz distante para iluminação geral
  color <1, 0.52, 0>
}


// câmera posicionada do lado esquerdo
camera {
  location <-100, 7, 40-deslocamento>     // Posição da câmera
  look_at <-60, 7, 30>      // Direção que a câmera está olhando
}

// ******  CENÁRIO  ******
// Instancia e posiciona a vaca
object {
  vaca()
  scale <3, 3, 3>
  rotate <0, 200, 0>
  translate <-65, 6, 40>  
}

// Vaca velha
object {
  vaca_velha()
  scale <3, 3, 3>
  rotate <0, 250, 0>
  translate <-78, 6, 30>  
}
