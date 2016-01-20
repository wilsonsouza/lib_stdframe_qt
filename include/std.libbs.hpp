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
#include <std.captions.hpp>
#include <std.menu.hpp>
#include <std.popup.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace Libbs
   {
      class Icons
      {
      public:
         QIcon MONEY;
         QIcon SAFEPAYMENT;
         QIcon PUBLIC;
         QIcon MAIL;
         QIcon FEMALE, MALE;
         QIcon COIN;
         QIcon NOTAFISCAL;
         QIcon CALCULATOR;
         QIcon CARDFILE;
         QIcon DOLAR;
         QIcon PRODUTOS;
         QIcon FORNECEDORES;
         QIcon CIDADES;

         QIcon APPEND;
         QIcon UPDATE;
         QIcon COMMIT;
         QIcon REMOVE;

         QIcon DETAILS;
         QIcon MODIFY;
      public:
         Icons()
         {
            MONEY = QIcon("money.ico");
            SAFEPAYMENT = QIcon("Safe-payment.ico");
            PUBLIC = QIcon("public.ico");
            MAIL = QIcon("mail.png");
            FEMALE = QIcon("Kdm-user-female.ico");
            MALE = QIcon("Kdm-user-male.ico");
            COIN = QIcon("/resoruces/Gold-Coin-Stacks-payment.ico");
            NOTAFISCAL = QIcon("invoice.ico");
            CALCULATOR = QIcon("calculator.ico");
            CARDFILE = QIcon("Card-File.ico");
            DOLAR = QIcon("banknote.ico");
            PRODUTOS = QIcon("App-ark.ico");
            FORNECEDORES = QIcon("Action-share.ico");
            CIDADES = QIcon("Company-Building.ico");
            APPEND = QIcon("Action-db-add.ico");
            UPDATE = QIcon("Action-db-Update.ico");
            COMMIT = QIcon("Action-db-commit.ico");
            REMOVE = QIcon("Action-db-remove.ico");
            DETAILS = QIcon("App-kservices.ico");
            MODIFY = QIcon("Action-reload.ico");
         }
      };
      //-----------------------------------------------------------------------------------------------//
      static ustring const IDSTERRITORIOMASK = ustring("99.99.99");
      static ustring const IDSCPFMASK        = ustring("999.999.999-99");
      static ustring const IDSCEPMASK        = ustring("9999-999");
      static ustring const IDSCNPJMASK       = ustring("999.999.999/9999-99");
      //-----------------------------------------------------------------------------------------------//
      class _DYNAMICLINK EquipeItems: public MenuItems
      {
      public:
         EquipeItems():MenuItems(Equipe::NAME)
         {
            MenuItems & p = *this;

            p + new MenuItemData(Equipe::CARGO);
            p + new MenuItemData(Equipe::MATRICULAS);
            p + new MenuItemData(Equipe::NCC);
            p + new MenuItemData(Equipe::REGIONAL);
            p + new MenuItemData(Equipe::VAGA);
         }

         DECLARE_OPERATOR(EquipeItems)
      };

      class _DYNAMICLINK DespesasItems: public MenuItems
      {
      public:
         DespesasItems():MenuItems(Despesas::NAME)
         {
            MenuItems & p = *this;

            p + new MenuItemData(Despesas::TIPO_DE_DESPESAS);
            p + new MenuItemData(Despesas::LANCA_OS_BB);
            p + new MenuItemData(Despesas::QUANTIDADES);

            MenuItemData * _v = new MenuItemData(Despesas::Valores::NAME);
            _v->operator+(new MenuItemData(Despesas::Valores::BASICOS));
            _v->operator+(new MenuItemData(Despesas::Valores::PESSOAIS));
            p + _v;

            MenuItemData * _c = new MenuItemData(Despesas::Controles::NAME);
            _c->operator+(new MenuItemData(Despesas::Controles::REMESSAS));
            _c->operator+(new MenuItemData(Despesas::Controles::EXTRATO_SAQUE));
            _c->operator+(new MenuItemData(Despesas::Controles::BANCO_RETORNO));
            p + _c;

            MenuItemData * _Agenda = new MenuItemData(Despesas::Controles::Agenda::NAME);
            _Agenda->operator+(new MenuItemData(Despesas::Controles::Agenda::PENDENTES));
            _Agenda->operator+(new MenuItemData(Despesas::Controles::Agenda::ENCERRADOS));
            _Agenda->operator+(new MenuItemData(Despesas::Controles::Agenda::ATUALIZAR));

            p + _Agenda;

            MenuItemData * _cc = new MenuItemData(Despesas::Controles::ContaCorrente::NAME);
            _cc->operator+(new MenuItemData(Despesas::Controles::ContaCorrente::LANCAMENTO_DE_RELATORIOS));
            p + _cc;

            using namespace Despesas::Controles::ContaCorrente;
            MenuItemData * _pc = new MenuItemData(PainelControle::NAME);
            _pc->operator+(new MenuItemData(PainelControle::TODOS_EXCETO_DEMITIDOS));
            _pc->operator+(new MenuItemData(PainelControle::EQUIPE_DE_CAMPO));
            _pc->operator+(new MenuItemData(PainelControle::DEMITIDOS));
            p + _pc;

            using namespace Despesas;
            MenuItemData * _s = new MenuItemData(Saldos::NAME);
            _s->operator+(new MenuItemData(Saldos::GERENCIAL));
            p + _s;

            MenuItemData * _g = new MenuItemData(Saldos::Contabil::NAME);
            _g->operator+(new MenuItemData(Saldos::Contabil::EXTRATO_DE_FUNCIONARIO));
            _g->operator+(new MenuItemData(Saldos::Contabil::SITUACAO_GERAL));
            p + _g;
         }

         DECLARE_OPERATOR(DespesasItems)
      };

      class _DYNAMICLINK BloqueioItems: public MenuItems
      {
      public:
         BloqueioItems():MenuItems(Bloqueio::NAME)
         {
            operator+(new MenuItemData(Bloqueio::BLOQUEAR_SALDOS_ANTERIORES));
         }

         DECLARE_OPERATOR(BloqueioItems)
      };

      class _DYNAMICLINK TabelasItems: public MenuItems, public Icons
      {
      public:
         TabelasItems():MenuItems(Tabelas::NAME)
         {
            MenuItems & p = *this;

            p + new MenuItemData(Tabelas::ATIVIDADES);
            p + new MenuItemData(Tabelas::CENTRO_DE_CUSTO, DOLAR);
            p + new MenuItemData(Tabelas::CIDADES, CIDADES);
            p + new MenuItemData(Tabelas::DIRETORIAS);

            MenuItemData * e = new MenuItemData(Tabelas::Eventos::NAME);
            e->operator+(new MenuItemData(Tabelas::Eventos::EVENTOS));
            e->operator+(new MenuItemData(Tabelas::Eventos::GASTOS));
            e->operator+(new MenuItemData(Tabelas::Eventos::GERENCIA_DE_PRODUTO));
            e->operator+(new MenuItemData(Tabelas::Eventos::PESSOAS_DE_CONTATO));
            e->operator+(new MenuItemData(Tabelas::Eventos::PRODUTOS));
            e->operator+(new MenuItemData(Tabelas::Eventos::RATEIO));
            e->operator+(new MenuItemData(Tabelas::Eventos::REGIONAIS));
            e->operator+(new MenuItemData(Tabelas::Eventos::TAREFAS));

            p + e;
            p + new MenuItemData(Tabelas::FORNECEDORES, FORNECEDORES);
            p + new MenuItemData(Tabelas::MEDICOS);
            p + new MenuItemData(Tabelas::TIPOS_DE_DESPESAS);
            p + new MenuItemData(Tabelas::TIPOS_DE_EVENTOS);

            MenuItemData * _p = new MenuItemData(Tabelas::Propagandistas::NAME);
            _p->operator+(new MenuItemData(Tabelas::Propagandistas::TODOS_EXCETO_DEMITIDOS));
            _p->operator+(new MenuItemData(Tabelas::Propagandistas::EQUIPE_DE_CAMPO));
            _p->operator+(new MenuItemData(Tabelas::Propagandistas::DEMITIDOS));

            p + _p;
         }

         DECLARE_OPERATOR(TabelasItems)
      };

      class _DYNAMICLINK VerbasItems: public MenuItems, public Icons
      {
      public:
         VerbasItems():MenuItems(Verbas::NAME)
         {
            operator+(new MenuItemData(Verbas::ANDAMENTO));
            operator+(new MenuItemData(Verbas::DISTRIBUICAO));
            operator+(new MenuItemData(Verbas::ENCERRADAS));
            operator+(new MenuItemData(Verbas::ENCERRAR));
            Separator();
            operator+(new MenuItemData(Verbas::GASTOS));
            operator+(new MenuItemData(Verbas::LANCAMENTOS));
            Separator();
            operator+(new MenuItemData(Verbas::LISTAGEM));
            operator+(new MenuItemData(Verbas::MULTIPLOS));
            Separator();
            operator+(new MenuItemData(Verbas::NOTAS_FISCAIS, NOTAFISCAL));
            operator+(new MenuItemData(Verbas::RDS));
            operator+(new MenuItemData(Verbas::RECALCULO, CALCULATOR));
            operator+(new MenuItemData(Verbas::TAREFAS));
            operator+(new MenuItemData(Verbas::VERIFICAO));
            operator+(new MenuItemData(Verbas::VERIFICAR_ORCAMENTO));
            operator+(new MenuItemData(Verbas::WWG));
         }

         DECLARE_OPERATOR(VerbasItems)
      };

      class _DYNAMICLINK PagamentosItems: public MenuItems, public Icons
      {
      public:
         PagamentosItems():MenuItems(Pagamentos::NAME)
         {
            operator+(new MenuItemData(Pagamentos::ESTATISTICA));
            operator+(new MenuItemData(Pagamentos::PAGAR, MONEY));
            Separator();
            operator+(new MenuItemData(Pagamentos::ADIANTAMENTOS_PENDENTES));
            operator+(new MenuItemData(Pagamentos::NORMAIS));
            operator+(new MenuItemData(Pagamentos::PENDENTES));
            operator+(new MenuItemData(Pagamentos::TODOS_ADIANTAMENTOS));
         }

         DECLARE_OPERATOR(PagamentosItems)
      };

      class _DYNAMICLINK FinanceiroItems: public MenuItems
      {
      public:
         FinanceiroItems():MenuItems(Financeiro::NAME)
         {
            operator+(new MenuItemData(Financeiro::CONTRATOS));
            operator+(new MenuItemData(Financeiro::GERAR_CARTA));
            operator+(new MenuItemData(Financeiro::LANCAMENTOS));
         }

         DECLARE_OPERATOR(FinanceiroItems)
      };

      class _DYNAMICLINK RomaneioItems: public MenuItems
      {
      public:
         RomaneioItems():MenuItems(Romaneio::NAME)
         {
            operator+(new MenuItemData(Romaneio::EMISSAO));
            operator+(new MenuItemData(Romaneio::NOTAS_FISCAIS));
         }

         DECLARE_OPERATOR(RomaneioItems)
      };

      class _DYNAMICLINK ControleVerbas: public Popup, public Icons
      {
      public:
         ControleVerbas():Popup(CONTROLE_DE_VERBAS)
         {
            operator+(new TabelasItems());
            operator+(new VerbasItems());
            operator+(new PagamentosItems());
            operator+(new FinanceiroItems());
            operator+(new RomaneioItems());
         }

         DECLARE_OPERATOR(ControleVerbas)
      };
   };      
};