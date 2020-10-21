## Ornella Olivastri - Legajo 1674201 - Curso K1051 - Año 2020 
---
## TP 4 - Tipo de dato Color
---

#### Aquí especifico matemáticamente el tipo de dato color

###### Conjunto de valores

{Color} = tipo de dato Color = { color = (x,y,z) / x,y,z  ϵ  N  ∧ 0 ≤ x,y,z ≤ 255 ]  }

###### Conjunto de operaciones

**Mezcla**(color 1, color 2) = color 3   /  color 3 = ( (x1+x2)/2, (y1+y2)/2, (z1+z2)/2 )  **∧** color 1, color 2, color 3 ϵ  {Color} 

**Suma**(color 1, color 2) = color 3   / color 3 = ( x1+x2, y1+y2, z1+z2 )
 **∧** x1+x2,y1+y2,z1+z2 > 255 →x1+x2,y1+y2,z1+z2 = 255 **∧** color 1, color 2, color 3 ϵ  {Color}

**Resta**(color 1, color 2) = color 3   /  color 3 = ( x-x2, y1-y2, z1-z2 )
 **∧** x-x2,y1-y2,z1-z2 < 0 →x-x2,y1-y2,z1-z2 = 0 **∧** color 1, color 2, color 3 ϵ  {Color}
