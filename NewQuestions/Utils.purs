module View.Stock.Container.PaymentPage.Utils where

import Prelude

import Data.Array (drop, filter, (!!))
import Data.Maybe (Maybe(..), fromMaybe)
import Data.String as StrUtils
import EC.Remote.Types (StoredCard(..), StoredWallet(..), Wallet(..))
import Effect (Effect)
import Engineering.Helpers.Commons (getIinFromName)
import PaymentPageConfig (ConfigPayload)
import PaymentPageConfig as PPConfig
import Payments.Core.Commons (UPIEnabledApps(..))
import PrestoDOM (Length(..), Margin(..), Padding(..), PrestoDOM, Visibility(..), alpha, color, fontStyle, height, margin, padding, text, textSize, textView, width)
import UI.Components.PaymentOptionsConfig as PaymentOptionsConfig
import UI.Components.PaymentOptionsView as PaymentOptionsView
import UI.Config as UIConfig
import UI.Utils (contentScrollId, upiScrollId)
import View.Common.Container.PaymentPage.Controller (Action(..), SelectedPaymentInstrument(..), State, comparePayInstrument)

getSectionHeader :: forall w  . String  -> ConfigPayload  -> PrestoDOM (Effect Unit) w
getSectionHeader headerText configPayload = 
    textView
        [ width MATCH_PARENT
        , height WRAP_CONTENT
        , text headerText
        , fontStyle $ UIConfig.fontBold configPayload
        , textSize (UIConfig.headerSize configPayload)
        , margin (Margin 0 0 0 12)
        , padding (Padding space 0 space 0)
        , color (UIConfig.fontColor configPayload)
        , alpha 0.7
        ]
    where 
     space = if contPadding == 0
                then UIConfig.globalSpacing configPayload
                else 0

     contPadding = PPConfig.getContainerPadding configPayload 


getSavedCardsView :: forall w  . (Action  -> Effect Unit) -> State -> Array StoredCard -> Array (PrestoDOM (Effect Unit) w)
getSavedCardsView push state savedCards = 
    ( map (\singleCard ->
        PaymentOptionsView.view  
        (push <<< (SavedPayOptionSelect (SavedCardItem singleCard))) 
        (getSavedCardConfig state singleCard) 
        false
        ) 
    $ (drop 1 savedCards))

getSavedCardConfig :: State -> StoredCard -> PaymentOptionsConfig.Config
getSavedCardConfig state (StoredCard card)= let
    space = UIConfig.globalSpacing state.configPayload
    PaymentOptionsConfig.Config config = (PaymentOptionsConfig.defConfig state.configPayload)
    listPaymentOptionsNew = config
        { cvvInputVisibility = VISIBLE
        , primaryText =  card.cardIssuer
        , secondaryText = card.cardNumber
        , secondaryTextColor = "#5C5C5C"
        , logoUrl = "ic_bank_" <> getIinFromName card.cardIssuer
        , radioButtonIconUrl = if (comparePayInstrument 
                                    (SavedCardItem (StoredCard card))
                                    state.selectedPaymentMethod
                                    )
                                then "tick_grey"
                                else "circular_radio_button"
        , radioButtonSize = V (UIConfig.radioIconSize state.configPayload)
        , inputAreaVisibility = if (comparePayInstrument 
                                        (SavedCardItem (StoredCard card)) 
                                        state.selectedPaymentMethod
                                    )
                                    then VISIBLE
                                    else GONE
        , buttonCornerRadius = PPConfig.getCornerRadius state.configPayload
        , startAnimation = state.buttonAnimation
        , cvvStroke = ("1," <> UIConfig.primaryColor state.configPayload)
        , cvvCornerRadius = PPConfig.getCornerRadius state.configPayload
        , animationVisibility = if state.buttonAnimation then VISIBLE else GONE
        , buttonAlpha = if (StrUtils.length state.cvv == 3) then 1.0 else 0.5
        , buttonClickable = if (StrUtils.length state.cvv == 3) then true else false
        , scrollId = contentScrollId
        }
    in (PaymentOptionsConfig.Config listPaymentOptionsNew )

getUpiAppsView :: forall w  . (Action  -> Effect Unit) -> State -> Array UPIEnabledApps -> Array (PrestoDOM (Effect Unit) w)
getUpiAppsView push state upiApps = 
    ( map (\upiApp ->
        PaymentOptionsView.view  
        (push <<< (UpiAppSelected (UpiApp upiApp))) 
        (getUpiAppConfig state upiApp)
        false
        ) 
    $ upiApps)

getUpiAppConfig :: State -> UPIEnabledApps -> PaymentOptionsConfig.Config
getUpiAppConfig state (UPIEnabledApps upiApp) = let
    isSelected = (comparePayInstrument 
                    (UpiApp (UPIEnabledApps upiApp))
                    state.selectedPaymentMethod
                    )
    space = UIConfig.globalSpacing state.configPayload
    PaymentOptionsConfig.Config config = (PaymentOptionsConfig.defConfig state.configPayload)
    listPaymentOptionsNew = config
        { cvvInputVisibility = GONE
        , buttonTextSize = (UIConfig.fontSize state.configPayload)
        , radioButtonSize = V (UIConfig.radioIconSize state.configPayload)
        , buttonBackground = UIConfig.primaryColor state.configPayload
        , buttonCornerRadius = PPConfig.getCornerRadius state.configPayload
        , primaryTextSize = UIConfig.fontSize state.configPayload
        , radioButtonIconUrl = if isSelected then "tick_grey" else "circular_radio_button"
        , inputAreaVisibility = if isSelected then VISIBLE else GONE
        , primaryText = upiApp.appName
        , logoUrl = upiApp.packageName
        , primaryTextFont = if isSelected then (UIConfig.fontBold state.configPayload) else (UIConfig.fontRegular state.configPayload)
        , secondaryTextVisibility = GONE
        -- , secondaryText = "Disabled"
        -- , secondaryTextSize = UIConfig.fontSizeSmall state.configPayload
        -- , secondaryTextColor = "#B22222"
        -- , secondaryTextFont = UIConfig.fontRegular state.configPayload
        -- , secondaryTextVisibility = if (isUpiAppDisabled upiApp.appName state) then VISIBLE else GONE
        -- , displayAreaAlpha = if (isUpiAppDisabled upiApp.appName state) then 0.5 else 1.0
        -- , radioButtonVisibility = if (isUpiAppDisabled upiApp.appName state) then GONE else VISIBLE
        , usePackageIcon = true
        , buttonFontStyle = UIConfig.fontBold state.configPayload
        , startAnimation = state.buttonAnimation
        , animationVisibility = if state.buttonAnimation then VISIBLE else GONE
        , logoSize = V (UIConfig.iconSize state.configPayload)
        , gridLogoSize = (V (UIConfig.iconSizeSmall state.configPayload))
        , lineSeparatorVisibility = UIConfig.lineSepVisibility state.configPayload
        , inputAreaHeight = V 60
        , logoPadding = (Padding space 0 0 0)
        , displayAreaHeight = (UIConfig.listItemHeight state.configPayload)
        , primaryTextColor = (UIConfig.fontColor state.configPayload)
        , scrollId = upiScrollId
        }
    in (PaymentOptionsConfig.Config listPaymentOptionsNew )

getWalletNameFromState :: State -> String
getWalletNameFromState state = 
    case state.selectedPaymentMethod of
        Just selectedInstrument ->
            case selectedInstrument of 
                SavedWalletItem selectedWallet -> do
                    let (StoredWallet (Wallet walletDetails)) = selectedWallet
                    (fromMaybe "" walletDetails.wallet)
                _ -> ""
        Nothing ->  ""

getDefaultOption :: State -> Maybe StoredCard
getDefaultOption state = state.savedCards !! 0

filterCards :: Maybe String -> Maybe String -> Maybe String -> Array StoredCard -> Array StoredCard
filterCards paymentMethod cardType cardIssuer savedCards = do
    let f1 = case paymentMethod of
                Just pm -> filter (\(StoredCard sc) -> sc.cardBrand == pm) savedCards
                Nothing -> savedCards
    let f2 = case cardType of
                Just ct -> filter (\(StoredCard sc) -> sc.cardType == ct) f1
                Nothing -> f1
    let f3 = case cardIssuer of
                Just bank -> filter (\(StoredCard sc) -> sc.cardIssuer == bank) f2
                Nothing -> f2
    f3