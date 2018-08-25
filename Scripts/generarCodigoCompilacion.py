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
comando = 'gcc {} -o Programa'

with open('invocar_compilador', 'w') as destino:
    destino.write('#!bin/bash\n')
    destino.write(comando.format(todosArchivos))