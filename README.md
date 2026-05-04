# 🌿 ZenScript Transpiler

![License](https://img.shields.io/badge/license-MIT-green)
![Version](https://img.shields.io/badge/version-1.0.0-blue)
![C++](https://img.shields.io/badge/compiler-C%2B%2B-orange)
![Python](https://img.shields.io/badge/target-Python-yellow)

O **ZenScript** é uma linguagem de script estruturada e declarativa. Este repositório contém o transpilador oficial escrito em C++ que converte código `.zs` em Python altamente otimizado ou executáveis nativos `.exe`.

## ✨ Funcionalidades

- **Sintaxe Limpa:** Estrutura baseada em blocos e declarativa.
- **CLI Poderosa:** Compilação simples via comando `zes`.
- **Portable:** Gere executáveis que rodam em qualquer lugar.
- **VS Code Support:** Extensão inclusa para Syntax Highlighting e IntelliSense.

## 🛠️ Arquitetura

O processo de compilação do ZenScript segue três etapas:
1. **Análise (C++):** O motor lê o arquivo `.zs` e valida a estrutura de classes e blocos.
2. **Tradução:** Mapeamento imediato para lógica Python e injeção de `__main__`.
3. **Packaging:** Uso opcional do PyInstaller para gerar um `.exe` isolado.

## 🚀 Como Usar

### 1. Instalação
Clone o repositório e compile o núcleo:
```bash
g++ zes.cpp -o zes
