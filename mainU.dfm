object frmMain: TfrmMain
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'VAM'
  ClientHeight = 533
  ClientWidth = 644
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object grpbItems: TGroupBox
    Left = 8
    Top = 151
    Width = 625
    Height = 162
    Caption = 'T'#233'tel'
    TabOrder = 0
    object Label2: TLabel
      Left = 26
      Top = 32
      Width = 38
      Height = 13
      Caption = 'Szla.jel:'
    end
    object Label4: TLabel
      Left = 384
      Top = 32
      Width = 47
      Height = 13
      Caption = 'Ad'#243'sz'#225'm:'
    end
    object Label6: TLabel
      Left = 26
      Top = 69
      Width = 44
      Height = 13
      Caption = #193'tutal'#225's:'
    end
    object Label8: TLabel
      Left = 208
      Top = 69
      Width = 48
      Height = 13
      Caption = 'Befizet'#233's:'
    end
    object Label10: TLabel
      Left = 26
      Top = 112
      Width = 123
      Height = 13
      Caption = 'T'#233'tel befizetett '#246'sszege: '
    end
    object Label11: TLabel
      Left = 384
      Top = 66
      Width = 65
      Height = 13
      Caption = 'EV azonos'#237't'#243':'
    end
    object Label12: TLabel
      Left = 384
      Top = 102
      Width = 27
      Height = 13
      Caption = 'VPID:'
    end
    object cbInvoiceSings1: TComboBox
      Left = 76
      Top = 29
      Width = 291
      Height = 21
      ItemIndex = 0
      TabOrder = 0
      Text = '01 (V'#225'mbev'#233'teli sz'#225'mla)'
      Items.Strings = (
        '01 (V'#225'mbev'#233'teli sz'#225'mla)'
        '02 (Importterm'#233'k '#193'FA bev'#233'teli sz'#225'mla)'
        '03'
        '05'
        '07 (V'#225'mp'#243'tl'#233'k bev'#233'teli sz'#225'mla)'
        '08'
        '09 (K'#246'rnyezetv'#233'delmi term'#233'kd'#237'j bev'#233'teli sz'#225'mla)'
        '10'
        '12 (V'#225'mlet'#233'tek let'#233'ti sz'#225'mla)'
        '14'
        '15'
        '17 (Illet'#233'k beszed'#233'si sz'#225'mla)'
        '41'
        '42 (Egy'#233'b term'#233'kek j'#246'ved'#233'ki ad'#243'ja sz'#225'mla)'
        '43 (B'#237'rs'#225'g, kamat bev'#233'teli sz'#225'mla)'
        '44'
        '45'
        '46'
        '47'
        '48 (J'#246'ved'#233'ki b'#237'rs'#225'g bev'#233'teli sz'#225'mla)'
        '49'
        '50'
        '51'
        '99 (K'#246'zponti k'#233'sedelmi p'#243'tl'#233'k bev'#233'teli sz'#225'mla)')
    end
    object dtItemsTransfer: TDateTimePicker
      Left = 76
      Top = 66
      Width = 105
      Height = 21
      Date = 41213.683390289350000000
      Time = 41213.683390289350000000
      TabOrder = 2
    end
    object edtItemsInvNr: TEdit
      Left = 540
      Top = 29
      Width = 65
      Height = 21
      MaxLength = 8
      TabOrder = 1
      Text = '11457695'
    end
    object dtItemsPay: TDateTimePicker
      Left = 262
      Top = 66
      Width = 105
      Height = 21
      Date = 41213.683390289350000000
      Time = 41213.683390289350000000
      TabOrder = 3
    end
    object edtItemSum: TEdit
      Left = 168
      Top = 109
      Width = 150
      Height = 21
      MaxLength = 11
      TabOrder = 5
      Text = '0'
    end
    object edtEVID: TEdit
      Left = 455
      Top = 63
      Width = 150
      Height = 21
      MaxLength = 14
      TabOrder = 4
    end
    object edtVPID: TEdit
      Left = 455
      Top = 99
      Width = 150
      Height = 21
      MaxLength = 12
      TabOrder = 7
      Text = 'HU0000000374'
    end
    object edtItemCents: TEdit
      Left = 324
      Top = 109
      Width = 29
      Height = 21
      MaxLength = 2
      TabOrder = 6
      Text = '0'
    end
    object bbtnAddItem: TBitBtn
      Left = 530
      Top = 126
      Width = 75
      Height = 25
      Caption = 'Hozz'#225'ad'
      DoubleBuffered = True
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33333333FF33333333FF333993333333300033377F3333333777333993333333
        300033F77FFF3333377739999993333333333777777F3333333F399999933333
        33003777777333333377333993333333330033377F3333333377333993333333
        3333333773333333333F333333333333330033333333F33333773333333C3333
        330033333337FF3333773333333CC333333333FFFFF77FFF3FF33CCCCCCCCCC3
        993337777777777F77F33CCCCCCCCCC3993337777777777377333333333CC333
        333333333337733333FF3333333C333330003333333733333777333333333333
        3000333333333333377733333333333333333333333333333333}
      NumGlyphs = 2
      ParentDoubleBuffered = False
      TabOrder = 8
      OnClick = bbtnAddItemClick
    end
  end
  object mLines: TMemo
    Left = 8
    Top = 319
    Width = 625
    Height = 177
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Courier'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object grpbHead: TGroupBox
    Left = 8
    Top = 8
    Width = 625
    Height = 137
    Caption = 'Fejsor'
    TabOrder = 2
    object Label1: TLabel
      Left = 26
      Top = 32
      Width = 38
      Height = 13
      Caption = 'Szla.jel:'
    end
    object Label3: TLabel
      Left = 384
      Top = 32
      Width = 47
      Height = 13
      Caption = 'Ad'#243'sz'#225'm:'
    end
    object Label5: TLabel
      Left = 26
      Top = 67
      Width = 44
      Height = 13
      Caption = #193'tutal'#225's:'
    end
    object Label7: TLabel
      Left = 208
      Top = 66
      Width = 48
      Height = 13
      Caption = 'Befizet'#233's:'
    end
    object Label9: TLabel
      Left = 26
      Top = 105
      Width = 136
      Height = 13
      Caption = 'Al'#225'bontott t'#233'telek '#246'sszege: '
    end
    object cbInvoiceSings: TComboBox
      Left = 76
      Top = 29
      Width = 291
      Height = 21
      ItemIndex = 0
      TabOrder = 0
      Text = '01 (V'#225'mbev'#233'teli sz'#225'mla)'
      Items.Strings = (
        '01 (V'#225'mbev'#233'teli sz'#225'mla)'
        '02 (Importterm'#233'k '#193'FA bev'#233'teli sz'#225'mla)'
        '03'
        '05'
        '07 (V'#225'mp'#243'tl'#233'k bev'#233'teli sz'#225'mla)'
        '08'
        '09 (K'#246'rnyezetv'#233'delmi term'#233'kd'#237'j bev'#233'teli sz'#225'mla)'
        '10'
        '12 (V'#225'mlet'#233'tek let'#233'ti sz'#225'mla)'
        '14'
        '15'
        '17 (Illet'#233'k beszed'#233'si sz'#225'mla)'
        '41'
        '42 (Egy'#233'b term'#233'kek j'#246'ved'#233'ki ad'#243'ja sz'#225'mla)'
        '43 (B'#237'rs'#225'g, kamat bev'#233'teli sz'#225'mla)'
        '44'
        '45'
        '46'
        '47'
        '48 (J'#246'ved'#233'ki b'#237'rs'#225'g bev'#233'teli sz'#225'mla)'
        '49'
        '50'
        '51'
        '99 (K'#246'zponti k'#233'sedelmi p'#243'tl'#233'k bev'#233'teli sz'#225'mla)')
    end
    object dtHeadTransfer: TDateTimePicker
      Left = 76
      Top = 65
      Width = 105
      Height = 21
      Date = 41213.683390289350000000
      Time = 41213.683390289350000000
      TabOrder = 2
    end
    object edtHeadInvNr: TEdit
      Left = 540
      Top = 29
      Width = 65
      Height = 21
      MaxLength = 8
      TabOrder = 1
      Text = '99999999'
    end
    object dtHeadPay: TDateTimePicker
      Left = 262
      Top = 65
      Width = 105
      Height = 21
      Date = 41213.683390289350000000
      Time = 41213.683390289350000000
      TabOrder = 3
    end
    object edtItemsSum: TEdit
      Left = 168
      Top = 102
      Width = 150
      Height = 21
      MaxLength = 11
      TabOrder = 4
      Text = '0'
    end
    object edtItemsCents: TEdit
      Left = 324
      Top = 102
      Width = 29
      Height = 21
      MaxLength = 2
      TabOrder = 5
      Text = '0'
    end
  end
  object bbtnSave: TBitBtn
    Left = 558
    Top = 502
    Width = 75
    Height = 25
    Caption = 'Ment'
    DoubleBuffered = True
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333FFFFFFFFFFFFF33000077777770033377777777777773F000007888888
      00037F3337F3FF37F37F00000780088800037F3337F77F37F37F000007800888
      00037F3337F77FF7F37F00000788888800037F3337777777337F000000000000
      00037F3FFFFFFFFFFF7F00000000000000037F77777777777F7F000FFFFFFFFF
      00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
      00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
      00037F7F333333337F7F000FFFFFFFFF07037F7F33333333777F000FFFFFFFFF
      0003737FFFFFFFFF7F7330099999999900333777777777777733}
    NumGlyphs = 2
    ParentDoubleBuffered = False
    TabOrder = 3
    OnClick = bbtnSaveClick
  end
  object dlgSave: TSaveDialog
    Filter = 'Text Files|*.txt'
    Left = 488
    Top = 8
  end
end
