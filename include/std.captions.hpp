//-----------------------------------------------------------------------------------------------//
// dedaluslib.lib for Windows
//
// Created by Wilson.Souza 2012
// For Libbs Farma
//
// Dedalus Prime
// (c) 2012
//-----------------------------------------------------------------------------------------------//
#pragma once
#include <std.defs.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace Shared
   {
      static ustring const SEARCHED = "Pesquisar";
      static ustring const DETAILS  = "Detalhes";
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Tokens
   {
      static const ustring nullstr = ustring();
      static const ustring SEPARATOR  = ustring("-");
      static const ustring STRINGEND  = ustring();
      static const QIcon nullIcon   = QIcon();
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Messages
   {
      static char const * INVALIDPOINTER = "Invalid pointer, variable %s";
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Errors
   {
      static ustring const CRITICAL = "Erro!!!";
      static ustring const QUESTION = ustring("Confirma?");
      static ustring const WARNING = ustring::fromLatin1("Atenção!");
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Styles
   {
      static const ustring WINDOWS   = ustring("windows");
      static const ustring FUSION    = ustring("fusion");
      static const ustring WINDOWSXP = ustring("windowsxp");
      static const ustring MACINTOSH = ustring("macintosh");
   };
   //-----------------------------------------------------------------------------------------------//
   namespace Captions
   {
      //-----------------------------------------------------------------------------------------------//
      static const ustring OK = ustring("&OK");
      static const ustring CANCEL = ustring("&Cancelar");
      static const ustring CONTINUE = ustring("Con&tinuar");
      static const ustring RETRY = ustring("&Repetir");
      static const ustring HELP = ustring("&Ajuda");

      static const ustring INSERT = ustring("&Incluir");
      static const ustring CHANGE = ustring("&Alterar");
      static const ustring DETAILS = ustring("&Detalhes");
      static const ustring REFRESH = ustring("&Atualizar");
      static const ustring ERASE = ustring("&Excluir");
      //-----------------------------------------------------------------------------------------------//
      namespace File
      {
         static const ustring NAME               = ustring("&Arquivo");
         static const ustring NEW                = ustring("&Novo");
         static const ustring OPEN               = ustring("&Abrir");
         static const ustring CLOSE              = ustring("&Fechar");
         static const ustring SAVE               = ustring("&Salvar");
         static const ustring SAVE_AS            = ustring("Salvar &Como");
         static const ustring PRINT              = ustring("&Imprimir");
         static const ustring PRINT_VIEW         = ustring::fromLatin1("&Visualizar Impressão");
         static const ustring PRINT_SETUP        = ustring::fromLatin1("Configurar Impressão");
         static const ustring PRINT_PAGE_SETUP   = ustring("Configurar pagina para impressão");
         static const ustring IMPORT             = ustring("Importar");
         static const ustring EXPORT             = ustring("Exportar");
         static const ustring RECENT_FILES       = ustring("&Recentes");
         static const ustring CHANGE_USER        = ustring::fromLatin1("&Trocar Usuário");
         static const ustring LOGOFF             = ustring("&Desligar Sistema");
         static const ustring EXIT               = ustring("&Sair");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace Edit
      {
         static const ustring NAME           = ustring("Editar");
         static const ustring UNDO           = ustring("Desfazer");
         static const ustring REDO           = ustring("Refazer");
         static const ustring CUT            = ustring("Recortar");
         static const ustring PASTE          = ustring("Colar");
         static const ustring COPY           = ustring("Copiar");
         static const ustring REMOVE         = ustring("Remover");
         static const ustring SELECT_ALL     = ustring("Selecionar Tudo");
         static const ustring FIND_REPLACE   = ustring("Pesquisar e Modificar");
         static const ustring GOTO           = ustring("Ir Para");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace View
      {
         static const ustring NAME           = ustring("Visualizar");
         static const ustring TOOLBAR        = ustring("Barra de Ferramentas");
         static const ustring STATUSBAR      = ustring("Barra de Estados");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace Tools
      {
         static const ustring NAME           = ustring("Ferramentas");
         static const ustring PREFERENCES    = ustring::fromLatin1("Preferências");
      };   
      //-----------------------------------------------------------------------------------------------//
      namespace Window
      {
         static const ustring NAME         = ustring("&Janela");
         static const ustring CLOSE        = ustring("&Fechar");
         static const ustring CLOSEALL     = ustring("Fechar &toda(s)");
         static const ustring MAXIMIZE     = ustring("&Maximizar");
         static const ustring MINIMIZE     = ustring("&Minimizar");
         static const ustring SHOW         = ustring("Mos&trar");
         static const ustring HIDE         = ustring("&Esconder");
         static const ustring REFRESH      = ustring("&Atualizar");
         static const ustring DOCUMENT     = ustring("Modo &documento");
         static const ustring TABBED       = ustring("Modo a&ba");
         static const ustring TILE         = ustring("Posicionar &lado a lado");
         static const ustring CASCADE      = ustring("Posicionar em &cascata");
         static const ustring NEXT         = ustring("&Proxima");
         static const ustring PREVIOUS     = ustring("Anterior");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace Style
      {
         static const ustring NAME          = ustring("Estilo");
         static const ustring WINDOWS       = ustring("Tipo &Windows Nativo");
         static const ustring MOTIF         = ustring("Tipo &Motif");
         static const ustring CDE           = ustring("Tipo &CDE");
         static const ustring PLASTIQUE     = ustring("Tipo &Plastique");
         static const ustring VISTA         = ustring("Tipo Windows &Vista");
         static const ustring XP            = ustring("Tipo Windows &XP");
         static const ustring MACINTOSH     = ustring("Tipo &Macintosh iOS");
         static const ustring FUSION        = ustring("Tipo &Fusion");
         static const ustring PART          = ustring("Tipo ");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace User
      {
         static const ustring NAME               = ustring::fromLatin1("Usuários");
         static const ustring PASSWORD           = ustring("Senha");
         static const ustring PERMISSION         = ustring::fromLatin1("Permissões");
         static const ustring MANAGER            = ustring::fromLatin1("Manutenção");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace Analyzer
      {
         static const ustring NAME           = ustring("Analisar");
         static const ustring PAGE           = ustring("Selecionar Tipo de Analise...");
      };
      //-----------------------------------------------------------------------------------------------//
      namespace Help
      {
         static const ustring NAME               = ustring("Ajuda");
         static const ustring INDEX              = ustring::fromLatin1("Índice da Ajuda");
         static const ustring LIBBS              = ustring("Libbs Home Page");
         static const ustring DEDALUS            = ustring("Dedalus Home Page");
         static const ustring WRDEVINFO          = ustring("WR DevInfo Home Page");
         static const ustring ABOUT              = ustring::fromLatin1("Sobre %1");
      };
   };//Captions
   //-----------------------------------------------------------------------------------------------//
   namespace Libbs
   {
      static ustring const CONTROLE_DE_VERBAS = "Controle de Verbas";

      namespace Equipe
      {
         static const ustring NAME = "&Equipe";
         static const ustring REGIONAL = "&Regional";
         static const ustring CARGO = "&Cargo";
         static const ustring VAGA = "&Vaga";
         static const ustring MATRICULAS = "&Matriculas";
         static const ustring NCC = ustring::fromLatin1("Número de conta corrente (N.C/C)");
      };
      namespace Despesas
      {
         static const ustring NAME = "&Despesas";
         static const ustring TIPO_DE_DESPESAS = "&Tipo de despesas";
         static const ustring QUANTIDADES = "&Quantidades";

         namespace Valores
         {
            static const ustring NAME = "&Valores";
            static const ustring BASICOS = "&Basicos";
            static const ustring PESSOAIS = "&Pessoais";
         };

         namespace Controles
         {
            static const ustring NAME = "&Controles";

            namespace ContaCorrente
            {
               static const ustring NAME = "&Conta corrente";
               static const ustring LANCAMENTO_DE_RELATORIOS = ustring::fromLatin1("&Lançamento de relatórios");

               namespace PainelControle
               {
                  static const ustring NAME = "&Painel de controle";
                  static const ustring TODOS_EXCETO_DEMITIDOS = ustring("&Todos exceto demitidos");
                  static const ustring EQUIPE_DE_CAMPO = "Equipe de campo";
                  static const ustring DEMITIDOS = "Demitidos";
               };
            };

            namespace Agenda
            {
               static const ustring NAME = "&Agenda";
               static const ustring PENDENTES = "&Pendentes";
               static const ustring ENCERRADOS = "&Encerrados";
               static const ustring ATUALIZAR = "A&tualizar";
            };

            static const ustring REMESSAS = "&Remessas";
            static const ustring BANCO_RETORNO = "&Banco retorno";
            static const ustring EXTRATO_SAQUE = "&Extrato de saque";
         };

         namespace Saldos
         {
            static const ustring NAME = "&Saldos";
            static const ustring GERENCIAL = "&Gerencial";

            namespace Contabil
            {
               static const ustring NAME = "&Contabil";
               static const ustring SITUACAO_GERAL = ustring("Situação geral");
               static const ustring EXTRATO_DE_FUNCIONARIO = ustring("Extrato de funcionário");
            };
         };

         static const ustring LANCA_OS_BB = ustring::fromLatin1("Lançamentos banco do brasil");
      };

      namespace Bloqueio
      {
         static const ustring NAME = "&Bloqueio";
         static const ustring BLOQUEAR_SALDOS_ANTERIORES = "Bloquear saldos anteriores";
      };

      namespace Tabelas
      {
         static const ustring NAME = "&Tabelas";

         namespace Eventos
         {
            static const ustring NAME = "&Eventos";
            static const ustring EVENTOS = ustring::fromLatin1("Manutenção de &eventos");
            static const ustring PESSOAS_DE_CONTATO = "Pessoas de &contato";
            static const ustring REGIONAIS = "Regionais";
            static const ustring PRODUTOS = "&Produtos";
            static const ustring GERENCIA_DE_PRODUTO = ustring::fromLatin1("Gerência de produto");
            static const ustring TAREFAS  = "&Tarefas";
            static const ustring GASTOS = "&Gastos";
            static const ustring RATEIO = "&Rateio";
         };

         static const ustring CIDADES = "&Cidades";
         static const ustring MEDICOS = ustring::fromLatin1("&Médicos");
         static const ustring CENTRO_DE_CUSTO = "Centro de custo";

         namespace Propagandistas
         {
            static const ustring NAME = "Propagandistas";
            static const ustring TODOS_EXCETO_DEMITIDOS = ustring("Todos exceto demitidos");
            static const ustring EQUIPE_DE_CAMPO = "&Equipe de campo";
            static const ustring DEMITIDOS = "&Demitidos";
         };

         static const ustring TIPOS_DE_DESPESAS = "&Tipos de despesas";
         static const ustring TIPOS_DE_EVENTOS = "Tipos de eventos";
         static const ustring DIRETORIAS = "&Diretorias";
         static const ustring FORNECEDORES = "&Fornecedores";
         static const ustring ATIVIDADES = "&Atividades";
      };

      namespace Verbas
      {
         static const ustring NAME = "&Verbas";
         static const ustring ANDAMENTO = "&Andamento";
         static const ustring ENCERRADAS = "&Encerradas";
         static const ustring DISTRIBUICAO = ustring::fromLatin1("&Distribuição");
         static const ustring GASTOS = "&Gastos";
         static const ustring LANCAMENTOS = ustring::fromLatin1("&Lançamentos");
         static const ustring MULTIPLOS = "Multiplos";
         static const ustring TAREFAS = "&Tarefas";
         static const ustring ENCERRAR = "Encerrar";
         static const ustring VERIFICAR_ORCAMENTO = ustring::fromLatin1("&Verificar orçamento");
         static const ustring RECALCULO = "&Recalculo";
         static const ustring LISTAGEM = "&Listagem";
         static const ustring RDS = "RDs";
         static const ustring WWG = ustring::fromLatin1("Solicitações de verbas vindos do sistema de cartões banco do brasil (WWG)");
         static const ustring NOTAS_FISCAIS = "&Notas fiscais";
         static const ustring VERIFICAO = ustring::fromLatin1("Verificação");
      };

      namespace Pagamentos
      {
         static const ustring NAME = "&Pagamentos";
         static const ustring NORMAIS = "&Normais";
         static const ustring PENDENTES = "Pendentes";
         static const ustring ADIANTAMENTOS_PENDENTES = "&Adiantamentos pendentes";
         static const ustring TODOS_ADIANTAMENTOS = "&Todos adiantamentos";
         static const ustring ESTATISTICA = "&Estatistica";
         static const ustring PAGAR = "Pagar";
      };

      namespace Financeiro
      {
         static const ustring NAME = "&Financeiro";
         static const ustring GERAR_CARTA = "&Gerar carta";
         static const ustring LANCAMENTOS = ustring::fromLatin1("Lançamentos");
         static const ustring CONTRATOS = "&Contratos";
      };

      namespace Romaneio
      {
         static const ustring NAME = "&Romaneio";
         static const ustring EMISSAO = ustring::fromLatin1("&Emissão");
         static const ustring NOTAS_FISCAIS = Verbas::NOTAS_FISCAIS;
      };
   };
};