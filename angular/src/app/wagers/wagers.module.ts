import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { WagerComponent } from './components/wager.component';
import { WagerItemComponent } from './components/wager-item.component';

@NgModule({
  imports: [
    CommonModule
  ],
  declarations: [
      WagerComponent,
      WagerItemComponent
  ],
    exports: [
        WagerComponent
    ]
})
export class WagersModule { }
