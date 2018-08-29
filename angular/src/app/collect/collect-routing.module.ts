import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {CollectHolderComponent} from './components/collect-holder.component';


const routes: Routes = [
  { path: 'collect',  component: CollectHolderComponent }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule]
})
export class CollectRoutingModule { }
