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
archivos = ['{}'.format(p.as_posix()) for p in sorted(obtenerArchivosC(directorio), key=lambda p: str(p))]
todosArchivos = ' '.join(archivos)
comando = 'gcc {} -o Programa -lm'
comandoDepuracion = comando + ' -g'

with open('./Scripts/invocar_compilador', 'w') as destino:
    destino.write('#!/bin/bash\n\n')
    destino.write(comando.format(todosArchivos))

with open('./Scripts/invocar_compilador.bat', 'w') as destino:
    destino.write('@echo off\n\n')
    destino.write(comando.format(todosArchivos))

with open('./Scripts/invocar_compilador_depuracion', 'w') as destino:
    destino.write('#!/bin/bash\n\n')
    destino.write(comandoDepuracion.format(todosArchivos))

with open('./Scripts/invocar_compilador_depuracion.bat', 'w') as destino:
    destino.write('@echo off\n\n')
    destino.write(comandoDepuracion.format(todosArchivos))