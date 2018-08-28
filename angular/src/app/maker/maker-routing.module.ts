import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { MakerHolderComponent } from './components/maker-holder.component';


const routes: Routes = [
  { path: 'make-bets',  component: MakerHolderComponent }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule]
})
export class MakerRoutingModule { }
