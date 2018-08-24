from typing import List
from pathlib import Path

def obtenerArchivosC(ruta: Path):
    def rec(rutaActual: Path, resultados: List[Path]):
        for carpeta in rutaActual.iterdir():
            actual = Path(carpeta)
            if actual.is_dir():
                rec(actual, resultados)
            elif actual.name.endswith('.c'):
                resultados.append(actual)

        return resultados

    return rec(ruta, [])


directorio = Path('.')
archivos = ['{}'.format(p) for p in obtenerArchivosC(directorio)]
todosArchivos = ' '.join(archivos)

with open('Scripts/invocar_compilador') as plantilla, open('invocar_compilador', 'w') as destino:
    for linea in plantilla.readlines():
        destino.write(linea.replace('$', todosArchivos))